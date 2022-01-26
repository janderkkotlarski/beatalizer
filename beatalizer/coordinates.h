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

  Vector3 m_pos
  { 1.0f, 0.0f, 0.0f };

  Vector3 m_dir
  { 0.0f, 1.0f, 0.0f };

  Vector3 m_rot
  { Vector3CrossProduct(m_pos, m_dir) };

public:
  coordinates();

  Vector3 get_pos();

  Vector3 get_dir();

  Vector3 get_rot();

  void set_pos(const Vector3 &pos);

  void set_dir(const Vector3 &dir);

  void random_pos_gold(auronacci &gold);

  void random_dir_gold(auronacci &gold);

  void perpendicular();
};

Vector3 random_pos_auro(auronacci &gold);

#endif // COORDINATES_H
