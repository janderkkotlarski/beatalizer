#ifndef COORDINATES_H
#define COORDINATES_H

#include <cmath>

#include "raylib.h"
#include "raymath.h"

#include "auronacci.h"

class coordinates
{
private:
  const float m_pi
  { float(M_PI) };

  Vector3 m_unit_x
  { 1.0f, 0.0f, 0.0f };

  Vector3 m_unit_y
  { 0.0f, 1.0f, 0.0f };

  Vector3 m_unit_z
  { 0.0f, 0.0f, 1.0f };

  Vector3 m_unit_pos
  { 1.0f, 0.0f, 0.0f };

  Vector3 m_unit_dir
  { 0.0f, 1.0f, 0.0f };

  Vector3 m_unit_rot
  { Vector3CrossProduct(m_unit_pos, m_unit_dir) };

public:
  coordinates();

  Vector3 get_pos();

  Vector3 get_unit_rot();

  void random_pos_time();

  void random_pos_gold(auronacci &gold);
};

#endif // COORDINATES_H
