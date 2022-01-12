#ifndef COORDINATES_H
#define COORDINATES_H

#include "raylib.h"
#include "raymath.h"

#include "auronacci.h"

class coordinates
{
private:
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

  Vector3 get_unit_pos();

  Vector3 get_unit_dir();

  Vector3 get_unit_rot();

  void random_pos_gold(auronacci &gold);
};

Vector3 random_pos_auro(auronacci &gold);

#endif // COORDINATES_H
