#include "timer.h"

timer::timer()
{
}

void timer::phase_reset() noexcept
{ m_beat_phase = 0.0f; }

float timer::get_phase()
noexcept
{ return m_beat_phase; }

void timer::add_time(const float time, const float beat_length)
{
  m_beat_phase += m_tau*time/(m_beat_mult*beat_length);

  if (m_beat_phase > m_tau)
  { m_beat_phase -= m_tau; }
}

uint64_t micros()
{
    uint64_t ms = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::
                  now().time_since_epoch()).count();
    return ms;
}
