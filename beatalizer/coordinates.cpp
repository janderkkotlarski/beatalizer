#include "coordinates.h"

#include <cmath>

#include "timer.h"

coordinates::coordinates()
{
}

Vector3 coordinates::get_pos()
{ return m_pos; }

Vector3 coordinates::get_dir()
{ return m_dir; }

Vector3 coordinates::get_rot()
{ return m_rot; }

void coordinates::set_pos(const Vector3 &pos)
{ m_pos = pos; }

void coordinates::set_dir(const Vector3 &dir)
{ m_dir = dir; }

void coordinates::perpendicular()
{
  m_rot = Vector3Normalize(Vector3CrossProduct(m_pos, m_dir));
  m_dir = Vector3Normalize(Vector3CrossProduct(m_rot, m_pos));
}
