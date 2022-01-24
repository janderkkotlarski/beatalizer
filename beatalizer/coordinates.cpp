#include "coordinates.h"

#include <cmath>

#include "timer.h"

coordinates::coordinates()
{
}

Vector3 coordinates::get_unit_pos()
{ return m_unit_pos; }

Vector3 coordinates::get_unit_dir()
{ return m_unit_dir; }

Vector3 coordinates::get_unit_rot()
{ return m_unit_rot; }

void coordinates::set_unit_dir(const Vector3 &dir)
{ m_unit_dir = dir; }

void coordinates::random_pos_gold(auronacci &gold)
{ m_unit_pos = random_pos_auro(gold); }

void coordinates::random_dir_gold(auronacci &gold)
{ m_unit_dir = random_pos_auro(gold); }

void coordinates::perpendicular()
{
  m_unit_rot = Vector3Normalize(Vector3CrossProduct(m_unit_pos, m_unit_dir));
  m_unit_dir = Vector3Normalize(Vector3CrossProduct(m_unit_rot, m_unit_pos));
}

Vector3 random_pos_auro(auronacci &gold)
{
  Vector3 unit_pos;

  const float pos_z
  { 2.0f*gold.get_fraction() - 1.0f };

  const float pos_xy
  { sqrt(1.0f - pos_z*pos_z) };

  const float phi
  { 2.0f*float(M_PI)*gold.get_fraction() };

  unit_pos.x = pos_xy*cos(phi);
  unit_pos.y = pos_xy*sin(phi);
  unit_pos.z = pos_z;

  return Vector3Normalize(unit_pos);
}
