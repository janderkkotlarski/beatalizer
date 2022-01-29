#include "form.h"

#include <iostream>

#include "functions.h"

form::form()
{
  m_coords.set_pos(Vector3{ 0.0f, 0.0f, 0.0f });
}

form::form(auronacci &gold)
{
  m_coords.random_pos_gold(gold);  
  m_coords.random_dir_gold(gold);
  m_coords.perpendicular();

  m_pos = Vector3Scale(m_coords.get_pos(), m_radius);

  set_next_pos();
}

form::form(auronacci &gold, const float phase_offset)
  : m_phase_offset(m_tau*phase_offset)
{
  m_coords.random_pos_gold(gold);
  m_coords.random_dir_gold(gold);
  m_coords.perpendicular();

  m_pos = Vector3Scale(m_coords.get_pos(), m_radius);

  set_next_pos();
}

void form::set_color()
{
  m_color =
  { unchar(distance_value(m_pos.x)),
    unchar(distance_value(m_pos.y)),
    unchar(distance_value(m_pos.z)),
    255};
}

float form::get_countdown() noexcept
{ return m_countdown; }

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
  const float countdown_phase
  { m_tau*period2float(m_period_countdown) };

  m_pos_next = orbit_pos(m_coords.get_pos(), m_coords.get_dir(), 1.0f, countdown_phase);
}

void form::set_period(timer &clock, auronacci &gold)
{
  m_period_countdown = period::p_8;

  m_coords.set_pos(m_pos_next);
  m_coords.random_dir_gold(gold);
  m_coords.perpendicular();

  set_next_pos();

  clock.set_phase(m_tau*m_countdown);

  m_countdown += period2float(m_period_countdown);  
}

void form::rephaser(timer &clock, auronacci &gold)
{
  m_phase_actual = clock.get_phase() + m_phase_offset;

  m_countdown -= clock.get_phase_fraction();

  if (m_countdown <= 0.0f)
  { set_period(clock, gold); }
}

void form::orbit()
{ m_pos = orbit_pos(m_coords.get_pos(), m_coords.get_dir(), m_distance, m_phase_actual/period2float(m_period_orbit)); }

void form::display_cuboid()
{ DrawCube(m_pos, m_side_x, m_side_y, m_side_z, m_color); }


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
