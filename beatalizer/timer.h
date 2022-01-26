#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <cmath>

class timer
{
private:
  const float m_tau
  { 2.0f*M_PI };

  float m_beat_phase
  { 0.0f };

  float m_phase_fraction
  { 0.0f };

  float m_tau_phase_fraction
  { 0.0f };

  const float m_beat_mult
  { 64.0f };

public:
  timer();

  void phase_reset() noexcept;

  float get_phase() noexcept;

  float get_phase_fraction() noexcept;

  float get_tau() noexcept;

  float get_tau_phase_fraction() noexcept;

  void add_time(const float time, const float beat_length);
};

uint64_t micros();

#endif // TIMER_H
