#include "prx/libc/include/general/VabiMacros.hpp"
#include <cstdlib>

extern "C" void APS5_VABI __tsan_acquire(void* address);
extern "C" void APS5_VABI __tsan_release(void* address);

static void Require(bool value) {
    if (!value)
        std::abort();
}

int main() {
    int value = 42;
    __tsan_acquire(&value);
    Require(value == 42);
    __tsan_release(&value);
    Require(value == 42);
}
