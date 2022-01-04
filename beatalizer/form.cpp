#include "form.h"

#include "functions.h"

form::form()
{
  m_coords.random_pos();

  m_pos = m_coords.get_pos();
}

form::form(const float phase_offset)
  : m_phase_offset(m_tau*phase_offset)
{

  m_coords.random_pos();

  m_pos = m_coords.get_pos();
}

void form::set_color()
{
  m_color =
  { unchar(distance_value(m_pos.x)),
    unchar(distance_value(m_pos.y)),
    unchar(distance_value(m_pos.z)),
    255};
}

void form::set_side(const float side)
{
  m_side_x = side;
  m_side_y = side;
  m_side_z = side;
}

void form::phasing(const float phase)
{
  const float phase_actual
  { phase + m_phase_offset };

  const float radius
  { m_radius*0.5f*(4.0f + 0.25f*static_cast<float>(cos(32.0f*phase_actual))) };

  m_pos.x = radius*m_side*cos(phase_actual)*sin(0.1f*sin(32.0f*phase_actual));
  m_pos.y = radius*m_side*sin(phase_actual)*cos(0.0f*cos(1.0f*phase_actual));
  m_pos.z = radius*m_side*cos(phase_actual)*cos(0.1f*sin(32.0f*phase_actual));

  // const float sine_phase
  // { 0.25f*m_side*float(fabs(sin(2.0f*phase_actual))) };

  // m_side_x = sine_phase;
  // m_side_y = sine_phase;
  // m_side_z = sine_phase;
}

void form::display_cuboid()
{
  DrawCube(m_pos, m_side_x, m_side_y, m_side_z, m_color);
}


float form::distance_value(const float pos)
{
  return 255.0f*0.25f*(3.0f + cos(4.0f*m_tau*pos/m_radius));
}

std::vector <form> form_sine_wave(const int number, const float side, const float phase_step)
{
  std::vector <form> cubes;


  const float tau_div
  { float(M_PI)/float(number) };

  for (int count { 1 }; count < number; ++count)
  {
    cubes.push_back(form(float(count)*phase_step));

    // cubes[count].set_side(side);

    cubes[count - 1].set_side(side*sin(float(count)*tau_div));
  }

  return cubes;
}
