#include "functions.h"

enum class period
{
  p__64, p__32, p__16, p__8, p__4, p__2,
  p_1, p_2, p_4, p_8, p_16, p_32, p_64, elements
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

int half_int(const int number)
{
  if (number % 2 == 1)
  { return (number + 1) / 2; }

  return number / 2;
}

unsigned char unchar(const float input)
{
  return static_cast<unsigned char>(input);
}

int period_size()
{
  return int(period::elements);
}

period periodic_all(auronacci &gold)
{
  const float all_peri
  { float(period_size()) };

  const int selector
  { int(all_peri*gold.get_fraction()) };

  return period(selector);
}

period periodic_low(auronacci &gold)
{
  const float low_peri
  { float(half_int(period_size())) };

  const int selector
  { int(low_peri*gold.get_fraction()) };

  return period(selector);
}

period periodic_mid(auronacci &gold)
{
  const int half_peri
  { half_int(period_size()) - 1 };

  const int quart_peri
  { half_int(half_peri) };

  const float low_peri
  { float(half_int(period_size())) };

  const int selector
  { quart_peri + int(low_peri*gold.get_fraction()) };

  return period(selector);
}

period periodic_high(auronacci &gold)
{
  const int half_peri
  { half_int(period_size()) - 1 };

  const float low_peri
  { float(half_int(period_size())) };

  const int selector
  { half_peri + int(low_peri*gold.get_fraction()) };

  return period(selector);
}

std::string period2string(const period &peri)
{
  switch (peri)
  {
    case period::p__64:
      return "[1/64]";
      break;
    case period::p__32:
      return "[1/32]";
      break;
    case period::p__16:
      return "[1/16]";
      break;
    case period::p__8:
      return "[1/8]";
      break;
    case period::p__4:
      return "[1/4]";
      break;
    case period::p__2:
      return "[1/2]";
      break;
    case period::p_1:
      return "[1]";
      break;
    case period::p_2:
      return "[2]";
      break;
    case period::p_4:
      return "[4]";
      break;
    case period::p_8:
      return "[8]";
      break;
    case period::p_16:
      return "[16]";
      break;
    case period::p_32:
      return "[32]";
      break;
    case period::p_64:
      return "[64]";
      break;
    case period::elements:
      return "[elements]";
      break;
  }

  return "None found!";
}
