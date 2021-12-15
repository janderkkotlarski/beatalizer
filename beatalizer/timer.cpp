#include "timer.h"

timer::timer()
{

}

void timer::phase_reset()
{
  m_16_beat_phase = 0.0f;
}

uint64_t micros()
{
    uint64_t ns = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::
                  now().time_since_epoch()).count();
    return ns;
}
