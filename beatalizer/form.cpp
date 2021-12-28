#include "form.h"



form::form()
{

}

form::form(const float phase_offset)
  : m_phase_offset(m_tau*phase_offset)
{
}

void form::set_color()
{
  m_red = 255.0f*m_pos.x/m_radius;
  m_green = 255.0f*m_pos.y/m_radius;
  m_blue = 255.0f*m_pos.z/m_radius;


  unsigned char beta
  { static_cast<unsigned char>(m_red) };
}

void form::phasing(const float phase)
{
  const float phase_actual
  { phase + m_phase_offset };

  m_pos.x = m_radius*m_side*cos(phase_actual)*sin(0.7f*sin(4.0f*phase_actual));
  m_pos.y = m_radius*m_side*sin(phase_actual);
  m_pos.z = m_radius*m_side*cos(phase_actual)*cos(0.3f*sin(8.0f*phase_actual));

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
