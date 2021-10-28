#include "timer.h"

#include <vector>

timer::timer()
{}

void timer::reset()
{ m_start = clock_type::now(); }

double timer::elapsed() const
{ return std::chrono::duration_cast<second_type>(clock_type::now() - m_start).count(); }

double cycler()
{
  std::vector <double> cycles;

  for (int count{ 0 }; count < 100; ++count)
  {
    const int start_ms
    { 300000 };

    int end
    { start_ms };

    const double peri
    { 0.0019 };

    timer tim;

    while (tim.elapsed() < peri)
    {
      ++end;

      int i
      { 0 };

      tim.reset();

      while (i < end)
      { ++i; }
    }

    cycles.push_back(double(end));
  }

  double average
  { 0.0 };

  for (const double cycle: cycles)
  { average += cycle; }

  average /= cycles.size();

  return average;
}
