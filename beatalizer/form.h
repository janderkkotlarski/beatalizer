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

  int m_identity
  { 0 };

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

  const float m_radius
  { 4.0f };

  float m_distance
  { m_radius };

  const float m_side
  { m_radius/16.0f };

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
  { period::p_32 };

  const float m_phase_8
  { 8.0f };

  const float m_phase_4
  { 4.0f };

  const float m_phase_2
  { 2.0f };

  const float m_phase_1
  { 1.0f };

  bool m_period_jump
  { false };

  float m_phase
  { 0.0f };

  float m_phase_offinit
  { 0.0f };

  float m_phase_offset
  { 0.0f };

  float m_phase_actual
  { 0.0f };

  float m_phase_arc
  { 0.0f };

  float m_jump_arc
  { 0.0f };

  float m_jump_step
  { 0.0f };

public:
  form();

  form(auronacci &gold);

  form(auronacci &gold, const float phase_offset);

  void initialize(auronacci &gold, form &cube);

  void phasing(auronacci &gold, form &cube);

  void orbiting();

  void longiverse();

  void orbitrans();

  void transradial();

  void transcircal();

  void standing_waves();

  float get_tau() noexcept;

  int get_identity() noexcept;

  float get_phase_offset() noexcept;

  period get_period_arc() noexcept;

  float get_jump_arc() noexcept;
  float get_jump_step() noexcept;

  void set_identity(const int identity);

  void set_period_phase(auronacci &gold, form &cube);

  void set_period_jump(const bool period_jump);

  void set_phase(const float phase);

  void set_color();
  void set_color(const Color &color);

  void set_side(const float side);

  void set_phase_offset(const float phase_offset);

  void set_next_pos(auronacci &gold, form &cube);

  void display_cuboid();

  float distance_value(const float pos);
};

std::vector <form> form_random_sphere(const int number, const float side, const float phase_step, auronacci &gold);

std::vector <form> form_random_arc(const int number, auronacci &gold);

#endif // FORM_H
