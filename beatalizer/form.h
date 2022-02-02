#ifndef FORM_H
#define FORM_H

#include <cmath>
#include <vector>

#include "raylib.h"

#include "coordinates.h"
#include "period.h"
#include "timer.h"

class form
{
private:  
  const float m_tau
  { 2.0f*M_PI };

  Color m_color
  { 255, 255, 255, 255};

  int m_red
  { 0 };

  int m_green
  { 0 };

  int m_blue
  { 0 };

  const Vector3 m_null_vector
  { 0.0f, 0.0f, 0.0f };

  Vector3 m_radial_x
  { 1.0f, 0.0f, 0.0f };

  Vector3 m_radial_y
  { 0.0f, 1.0f, 0.0f };

  Vector3 m_radial_z
  { 0.0f, 0.0f, 1.0f };

  Vector3 m_position_now
  { m_null_vector };

  Vector3 m_position_stop
  { m_null_vector };

  Vector3 m_pos
  { m_null_vector };

  Vector3 m_pos_next
  { m_null_vector };

  Vector3 m_pos_delta
  { m_null_vector };

  coordinates m_coords;

  Vector3 m_previous
  { m_null_vector };

  Vector3 m_jump
  { m_null_vector };

  const float m_radius
  { 4.0f };

  float m_distance
  { m_radius };

  const float m_side
  { 0.05f };

  float m_side_x
  { m_side };

  float m_side_y
  { m_side };

  float m_side_z
  { m_side };

  period m_period_step
  { period::p_2 };

  period m_period_arc
  { period::p_4 };

  period m_period_orbit
  { period::p_16 };

  float m_phase_offset
  { 0.0f };

  float m_phase_actual
  { 0.0f };

  float m_phase_arc
  { 0.0f };

public:
  form();

  form(auronacci &gold);

  form(auronacci &gold, const float phase_offset);

  void phasing(timer &clock, auronacci &gold);

  void move();

  void orbiting();

  float get_countdown() noexcept;

  Vector3 get_pos() noexcept;

  Vector3 get_pos_next() noexcept;

  Vector3 get_pos_delta() noexcept;

  float get_jump() noexcept;

  void set_period_phase();

  void set_color();

  void set_color(const Color &color);

  void set_side(const float side);

  void set_phase_offset(const float phase_offset);

  void set_distance();

  void set_dir(const Vector3 &dir);

  void set_next_pos(auronacci &gold);

  void set_period(timer &clock, auronacci &gold);

  void display_cuboid();

  float distance_value(const float pos);
};

std::vector <form> form_random_sphere(const int number, const float side, const float phase_step, auronacci &gold);

std::vector <form> form_random_arc(const int number, const float side, auronacci &gold);

#endif // FORM_H
