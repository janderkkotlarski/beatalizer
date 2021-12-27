#include "form.h"



form::form()
{

}

form::form(const float phase_offset)
  : m_phase_offset(m_tau*phase_offset)
{
}

void form::set_color(const Color color)
{
  m_color = color;
}

void form::phasing(const float phase)
{
  const float phase_actual
  { phase + m_phase_offset };

  m_pos.y = 2.0f*m_side*sin(phase_actual);
  m_pos.z = 2.0f*m_side*cos(phase_actual);

  const float sine_phase
  { 0.25f*m_side*float(fabs(sin(phase_actual))) };

  m_side_x = sine_phase;
  m_side_y = sine_phase;
  m_side_z = sine_phase;
}

void form::display_cuboid()
{
  DrawCube(m_pos, m_side_x, m_side_y, m_side_z, m_color);
}
