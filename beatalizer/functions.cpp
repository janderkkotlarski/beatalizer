#include "functions.h"

enum class frequ
{
  f__64, f__32, f__16, f__8, f__4, f__2,
  f_1, f_2, f_4, f_8, f_16, f_32, f_64
};

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

unsigned char unchar(float input)
{
  return static_cast<unsigned char>(input);
}

float frequify_all(auronacci &gold)
{
  const int selector
  { int(13.0f*gold.get_fraction()) };
}
