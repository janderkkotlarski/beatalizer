#include "functions.h"

#include <cmath>

#include "raymath.h"

enum class trigon
{
  sine, cosine
};

enum class movement
{
  still, orbit, radial, trans, longit
};

enum class dimension
{
  steady, oscillate
};

enum class coloring
{
  red, green, blue, opacity
};

int half_int(const int number)
{
  if (number % 2 == 1)
  { return (number + 1) / 2; }

  return number / 2;
}

unsigned char unchar(const float input)
{ return static_cast<unsigned char>(input); }

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

void normandicular(Vector3 &pos_x, Vector3 &pos_y, Vector3 &pos_z)
{
  pos_x = Vector3Normalize(pos_x);
  pos_z = Vector3Normalize(Vector3CrossProduct(pos_x, pos_y));
  pos_y = Vector3Normalize(Vector3CrossProduct(pos_z, pos_x));
}

Vector3 orbit_pos(const Vector3 &pos, const Vector3 &dir,
                  const float dist, const float phase)
{
  return Vector3Add(Vector3Scale(pos, dist*cos(phase)),
                    Vector3Scale(dir, dist*sin(phase)));
}

void orbit_jump(Vector3 &pos, Vector3 &dir, const float phase)
{
  const Vector3 pos_c
  { Vector3Normalize(orbit_pos(pos, dir, 1.0f, phase)) };

  Vector3 dir_c
  { Vector3Normalize(orbit_pos(dir, Vector3Negate(pos), 1.0f, phase)) };

  pos = pos_c;
  dir = dir_c;
}

std::vector <int> color2ints(const Color &color)
{
  std::vector <int> ints;

  ints.push_back(color.r);
  ints.push_back(color.g);
  ints.push_back(color.b);
  ints.push_back(color.a);

  return ints;
}
