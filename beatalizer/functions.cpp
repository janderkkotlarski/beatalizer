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
