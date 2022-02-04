#include "form.h"

#include <iostream>
#include <cassert>

#include "functions.h"

form::form()
{
}

form::form(auronacci &gold)
{
  initialize(gold);
}

form::form(auronacci &gold, const float phase_offset)
  : m_phase_offset(m_tau*phase_offset)
{
  initialize(gold);
}

void form::initialize(auronacci &gold)
{
  m_radial_x = random_pos_auro(gold);
  m_radial_y = random_pos_auro(gold);

  normandicular(m_radial_x, m_radial_y, m_radial_z);

  set_period_phase(gold);

  orbiting();
}

void form::orbiting()
{
  const float next_phase
  { m_phase_actual/period2float(m_period_orbit) };

  m_position_now = orbit_pos(m_radial_x, m_radial_y, m_distance, next_phase);
}

float form::get_phase_offset() noexcept
{ return m_phase_offset; }

void form::set_period_phase(auronacci &gold)
{
  m_period_arc = periodic_mid_high(gold);
  m_phase_arc = m_tau*period2float(m_period_arc);
}

void form::set_color()
{
  m_color =
  { unchar(distance_value(m_position_now.x)),
    unchar(distance_value(m_position_now.y)),
    unchar(distance_value(m_position_now.z)),
    255
  };
}

void form::set_color(const Color &color)
{ m_color = color; }

void form::set_side(const float side)
{
  m_side_x = side;
  m_side_y = side;
  m_side_z = side;
}

void form::set_phase_offset(const float phase_offset)
{ m_phase_offset = phase_offset; }

void form::set_next_pos(auronacci &gold)
{
  const float arc_phase
  { m_phase_arc/period2float(m_period_orbit) };

  orbit_jump(m_radial_x, m_radial_y, arc_phase);

  const float step_phase
  { m_tau*gold.get_fraction() };

  orbit_jump(m_radial_y, m_radial_z, step_phase);
}

void form::phasing(timer &clock, auronacci &gold)
{
  m_phase_actual = clock.get_phase() + m_phase_offset;

  if (m_phase_actual > m_phase_arc)
  {
    set_next_pos(gold);

    m_phase_offset -= m_phase_arc;

    set_period_phase(gold);

    m_phase_actual = clock.get_phase() + m_phase_offset;
  }
}

void form::display_cuboid()
{ DrawCube(m_position_now, m_side_x, m_side_y, m_side_z, m_color); }


float form::distance_value(const float pos)
{
  return 255.0f*0.25f*(3.0f + cos(4.0f*m_tau*pos/m_radius));
}

std::vector <form> form_random_sphere(const int number, const float side, const float phase_step, auronacci &gold)
{
  std::vector <form> cubes;

  const float tau_div
  { float(M_PI)/float(number) };

  for (int count { 1 }; count < number; ++count)
  { cubes.push_back(form(gold, float(count)*phase_step)); }

  return cubes;
}

std::vector <form> form_random_arc(const int number, const float side, auronacci &gold)
{
  const float scale
  { 8.0f };

  std::vector <form> cubes;

  const float divided
  { 1.0f/64.0f };

  const float tau
  { float(2.0*M_PI) };

  cubes.push_back(form(gold, 0.0f));

  cubes[0].set_side(side);

  for (int count { 1 }; count < number; ++count)
  {
    cubes.push_back(cubes[0]);

    cubes[count].set_phase_offset(tau*divided*float(count));

    cubes[count].set_side(side);
  }

  return cubes;
}
