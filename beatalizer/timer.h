#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <cmath>

class timer
{
private:
  const float m_tau
  { 2.0f*M_PI };

  float m_16_beat_phase
  { 0.0f };



public:
  timer();

  void phase_reset() noexcept;

  float get_phase() noexcept;

  void add_time(const float time, const float beat_length);
};

uint64_t micros();

#endif // TIMER_H
