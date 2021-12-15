#ifndef TIMER_H
#define TIMER_H

#include <chrono> // for std::chrono functions

class timer
{
private:
  float m_16_beat_phase
  { 0.0f };



public:
  timer();

  void phase_reset();


};

uint64_t micros();

#endif // TIMER_H
