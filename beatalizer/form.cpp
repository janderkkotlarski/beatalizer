#include "form.h"

#include <iostream>
#include <cassert>

#include "functions.h"

form::form()
{
  m_coords.set_pos(Vector3{ 0.0f, 0.0f, 0.0f });

  set_period_phase();

  // orbiting();
}

form::form(auronacci &gold)
{
  m_coords.random_pos_gold(gold);  
  m_coords.random_dir_gold(gold);
  m_coords.perpendicular();

  m_pos = Vector3Scale(m_coords.get_pos(), m_radius);

  set_period_phase();

  // set_next_pos();

  orbiting();
}

form::form(auronacci &gold, const float phase_offset)
  : m_phase_offset(m_tau*phase_offset)
{
  m_coords.random_pos_gold(gold);
  m_coords.random_dir_gold(gold);
  m_coords.perpendicular();

  m_pos = Vector3Scale(m_coords.get_pos(), m_radius);

  set_period_phase();

  // set_next_pos();

  orbiting();
}

void form::move()
{
  orbiting();
}

void form::orbiting()
{
  const float next_phase
  { m_phase_actual/period2float(m_period_orbit) };

  m_position_now = orbit_pos(m_radial_x, m_radial_y, m_distance, next_phase);
}



Vector3 form::get_pos() noexcept
{ return m_coords.get_pos(); }

Vector3 form::get_pos_next() noexcept
{ return m_pos_next; }

Vector3 form::get_pos_delta() noexcept
{ return m_pos_delta; }

float form::get_jump() noexcept
{ return Vector3Length(m_jump); }

void form::set_period_phase()
{ m_phase_arc = m_tau*period2float(m_period_arc); }

void form::set_color()
{
  m_color =
  { unchar(distance_value(m_pos.x)),
    unchar(distance_value(m_pos.y)),
    unchar(distance_value(m_pos.z)),
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

void form::set_distance()
{ m_distance = m_radius; }

void form::set_dir(const Vector3 &dir)
{
  m_coords.set_dir(dir);
  m_coords.perpendicular();
}

void form::set_next_pos()
{
  const float next_phase
  { m_phase_arc/period2float(m_period_orbit) };

  const Vector3 radial_x
  { Vector3Normalize(orbit_pos(m_radial_x, m_radial_y, 1.0f, next_phase)) };

  const Vector3 radial_y
  { Vector3Normalize(orbit_pos(m_radial_y, Vector3Negate(m_radial_x), 1.0f, next_phase)) };

  m_radial_x = radial_x;
  m_radial_y = radial_y;
}

void form::set_period(timer &clock, auronacci &gold)
{
  m_period_countdown = period::p_8;

  m_coords.set_pos(m_pos_next);
  m_coords.random_dir_gold(gold);
  m_coords.perpendicular();

  set_next_pos();

  m_pos_delta = Vector3Add(m_pos_next, Vector3Negate(m_coords.get_pos()));
}

void form::phasing(timer &clock)
{
  m_phase_actual = clock.get_phase() + m_phase_offset;

  if (m_phase_actual > m_phase_arc)
  {
    set_next_pos();

    m_phase_offset -= m_phase_arc;

    set_period_phase();

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
