#include "timer.h"

timer::timer()
{}

void timer::reset()
{ m_start = clock_type::now(); }

double timer::elapsed() const
{ return std::chrono::duration_cast<second_type>(clock_type::now() - m_start).count(); }

std::vector <double> cycler(const int cycle_step, const int repeats)
{
  std::vector <double> cycles;

  for (int count{ 0 }; count < repeats; ++count)
  {
    int end
    { cycle_step };

    timer tim;

    for (int count2 {0}; count2 < end; ++count2)
    { }

    cycles.push_back(tim.elapsed());
  }

  return cycles;
}

double average(const std::vector <double> &numbers)
{
  if (numbers.size() == 0)
  { return 0.0; }

  double culu
  { 0.0 };

  for (const double number: numbers)
  { culu += number; };

  return culu/numbers.size();
}

uint64_t nanos()
{
    uint64_t ns = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::
                  now().time_since_epoch()).count();
    return ns;
}
