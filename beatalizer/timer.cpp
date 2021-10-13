#include "timer.h"

timer::timer()
{}

void timer::reset()
{ m_start = clock_type::now(); }

double timer::elapsed() const
{ return std::chrono::duration_cast<second_type>(clock_type::now() - m_start).count(); }
