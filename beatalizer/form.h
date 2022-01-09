#ifndef FORM_H
#define FORM_H

#include <cmath>
#include <vector>

#include "raylib.h"

#include "coordinates.h"

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

  Vector3 m_pos
  { 0.0f, 0.0f, 0.0f };

  coordinates m_coords;

  const float m_radius
  { 4.0f };

  const float m_side
  { 0.03f };

  float m_side_x
  { m_side };

  float m_side_y
  { m_side };

  float m_side_z
  { m_side };

  const float m_phase_offset
  { 0.0f };

public:
  form(auronacci &gold);

  form(auronacci &gold, const float phase_offset);

  void set_color();

  void set_side(const float side);

  void phasing(const float phase);

  void display_cuboid();

  float distance_value(const float pos);
};

std::vector <form> form_sine_wave(const int number, const float side, const float phase_step, auronacci &gold);

#endif // FORM_H
