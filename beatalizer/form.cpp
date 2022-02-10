#include "form.h"

#include <iostream>
#include <cassert>

#include "functions.h"

form::form()
{
}

form::form(auronacci &gold)
{
}

form::form(auronacci &gold, const float phase_offset)
  : m_phase_offinit(phase_offset), m_phase_offset(phase_offset)
{
}

void form::initialize(auronacci &gold, form &cube)
{
  m_radial_x = random_pos_auro(gold);
  m_radial_y = random_pos_auro(gold);

  normandicular(m_radial_x, m_radial_y, m_radial_z);

  set_period_phase(gold, cube);

  orbiting();
}

void form::orbiting()
{
  const float next_phase
  { m_phase_actual/period2float(m_period_orbit) };

  m_position_now = orbit_pos(m_radial_x, m_radial_y, m_distance, next_phase);
}

void form::longiverse()
{
  const float phase_mult
  { 1.0f/4.0f };

  const float phase_slowed
  { phase_mult*(m_phase + m_phase_offinit) };

  const float phase_scale
  { m_tau/4.0f };

  const float next_phase
  { (m_phase_actual + phase_scale*cos(phase_slowed))/period2float(m_period_orbit) };

  m_position_now = orbit_pos(m_radial_x, m_radial_y, m_distance, next_phase);
}

void form::orbitrans()
{
  const float next_phase
  { m_phase_actual/period2float(m_period_orbit) };

  const Vector3 zenith
  { orbit_pos(m_radial_y, Vector3Negate(m_radial_x), m_distance, next_phase) };

  const float phase_slowed
  { (m_phase + m_phase_offinit)/m_phase_2 };

  const float twiddle
  { 0.03f*sin(phase_slowed) };

  m_position_now = orbit_pos(m_position_now, zenith, 1.0f, twiddle);
}

void form::transradial()
{
  const float phase_slowed
  { (m_phase + m_phase_offinit)/m_phase_4 };

  const float transwave
  { 1.0f + 0.1f*sin(phase_slowed) };

  m_position_now = Vector3Scale(m_position_now, transwave);
}

void form::transcircal()
{
  const float phase_slowed
  { (m_phase + m_phase_offinit)/m_phase_2 };

  const float twiddle
  { 0.03f*sin(phase_slowed) };

  m_position_now = orbit_pos(m_position_now, Vector3Scale(m_radial_z, m_distance), 1.0f, twiddle);
}

void form::standing_waves()
{
  const float phase_slowed
  { (m_phase + m_phase_offinit)/m_phase_8 };

  m_side_x = m_side*sin(phase_slowed);
  m_side_y = m_side*sin(phase_slowed);
  m_side_z = m_side*sin(phase_slowed);
}

float form::get_tau() noexcept
{ return m_tau; }

int form::get_identity() noexcept
{ return m_identity; }

float form::get_phase_offset() noexcept
{ return m_phase_offset; }

period form::get_period_arc() noexcept
{ return m_period_arc; }

float form::get_jump_arc() noexcept
{ return m_jump_arc; }

float form::get_jump_step() noexcept
{ return m_jump_step; }

void form::set_identity(const int identity)
{ m_identity = identity; }

void form::set_period_phase(auronacci &gold, form &cube)
{
  if (m_identity == 0)
  { m_period_arc = periodic_mid_high(gold); }
  else
  { m_period_arc = cube.get_period_arc(); }

  m_phase_arc = m_tau*period2float(m_period_arc);
}

void form::set_phase(const float phase)
{ m_phase = phase; }

void form::set_color()
{
  m_color =
  { unchar(distance_value(m_position_now.x)),
    unchar(distance_value(m_position_now.y)),
    unchar(distance_value(m_position_now.z)),
    255 };

  if (m_period_jump)
  { m_color = WHITE; }
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
{
  m_phase_offinit = phase_offset;
  m_phase_offset = phase_offset;
}

void form::set_period_jump(const bool period_jump)
{ m_period_jump = period_jump; };

void form::set_next_pos(auronacci &gold, form &cube)
{

  if (m_identity == 0)
  { m_jump_arc = m_phase_arc/period2float(m_period_orbit); }
  else
  { m_jump_arc = cube.get_jump_arc(); }

  orbit_jump(m_radial_x, m_radial_y, m_jump_arc);

  if (m_identity == 0)
  { m_jump_step = m_tau*gold.get_fraction(); }
  else
  { m_jump_step = cube.get_jump_step(); }

  orbit_jump(m_radial_y, m_radial_z, m_jump_step);
}

void form::phasing(auronacci &gold, form& cube)
{
  m_phase_actual = m_phase + m_phase_offset;

  if (m_phase_actual > m_phase_arc
      && false)
  {
    set_next_pos(gold, cube);

    m_phase_offset -= m_phase_arc;

    set_period_phase(gold, cube);

    m_phase_actual = m_phase + m_phase_offset;
  }

  if (m_period_jump)
  { m_phase_actual += m_tau*period2float(period::p_1); }
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

std::vector <form> form_random_arc(const int number, auronacci &gold)
{
  const float tau
  { float(2.0*M_PI) };

  std::vector <form> cubes;

  cubes.push_back(form(gold));
  cubes[0].initialize(gold, cubes[0]);

  const float beat_division
  { float(number) };

  const float divided
  { 4.0f/beat_division };

  for (int count { 1 }; count < number; ++count)
  {
    cubes.push_back(cubes[0]);

    cubes[count].set_phase_offset(-tau*divided*float(count));
    cubes[count].set_identity(count);
  }

  return cubes;
}
