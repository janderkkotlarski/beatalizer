#include "timer.h"

timer::timer()
  : m_beat_phase(0.0f)
{
}

void timer::phase_reset() noexcept
{ m_beat_phase = 0.0f; }

float timer::get_phase()
noexcept
{ return m_beat_phase; }

float timer::get_phase_fraction()
noexcept
{ return m_phase_fraction; }

float timer::get_tau()
noexcept
{ return m_tau; }

float timer::get_tau_phase_fraction()
noexcept
{ return m_tau_phase_fraction; }

void timer::add_time(const float time, const float beat_length)
{
  m_phase_fraction = time/beat_length;

  m_tau_phase_fraction = m_tau*time/beat_length;

  m_beat_phase += m_tau_phase_fraction;

  // if (m_beat_phase > m_tau)
  // { m_beat_phase -= m_tau; }
}

uint64_t micros()
{
    uint64_t ms = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::
                  now().time_since_epoch()).count();
    return ms;
}
