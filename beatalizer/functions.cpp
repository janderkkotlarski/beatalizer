#include "functions.h"

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




