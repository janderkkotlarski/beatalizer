#include "timer.h"

uint64_t micros()
{
    uint64_t ns = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::
                  now().time_since_epoch()).count();
    return ns;
}
