#include "timer.h"

timer::timer()
{

}

void timer::phase_reset() noexcept
{
  m_16_beat_phase = 0.0f;
}

float timer::get_phase()
noexcept
{
  return m_16_beat_phase;
}

void timer::add_time(const float time, const float beat_length)
{
  m_16_beat_phase += m_tau*time/(16.0f*beat_length);

  if (m_16_beat_phase > m_tau)
  { m_16_beat_phase -= m_tau; }
}

uint64_t micros()
{
    uint64_t ns = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::
                  now().time_since_epoch()).count();
    return ns;
}
