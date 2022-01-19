#include "functions.h"

enum class frequ
{
  f__64, f__32, f__16, f__8, f__4, f__2,
  f_1, f_2, f_4, f_8, f_16, f_32, f_64, elements
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

int frequ_size()
{
  return int(frequ::elements);
}

frequ frequify_all(auronacci &gold)
{
  const float all_freq
  { float(frequ_size()) };

  const int selector
  { int(all_freq*gold.get_fraction()) };

  return frequ(selector);
}

frequ frequify_low(auronacci &gold)
{
  const float low_freq
  { float(half_int(frequ_size())) };

  const int selector
  { int(low_freq*gold.get_fraction()) };

  return frequ(selector);
}

frequ frequify_mid(auronacci &gold)
{
  const int half_freq
  { half_int(frequ_size()) - 1 };

  const int quart_freq
  { half_int(half_freq) };

  const float low_freq
  { float(half_int(frequ_size())) };

  const int selector
  { quart_freq + int(low_freq*gold.get_fraction()) };

  return frequ(selector);
}

frequ frequify_high(auronacci &gold)
{
  const int half_freq
  { half_int(frequ_size()) - 1 };

  const float low_freq
  { float(half_int(frequ_size())) };

  const int selector
  { half_freq + int(low_freq*gold.get_fraction()) };

  return frequ(selector);
}

std::string frequ2string(const frequ &freq)
{
  switch (freq)
  {
    case frequ::f__64:
      return "[1/64]";
      break;
    case frequ::f__32:
      return "[1/32]";
      break;
    case frequ::f__16:
      return "[1/16]";
      break;
    case frequ::f__8:
      return "[1/8]";
      break;
    case frequ::f__4:
      return "[1/4]";
      break;
    case frequ::f__2:
      return "[1/2]";
      break;
    case frequ::f_1:
      return "[1]";
      break;
    case frequ::f_2:
      return "[2]";
      break;
    case frequ::f_4:
      return "[4]";
      break;
    case frequ::f_8:
      return "[8]";
      break;
    case frequ::f_16:
      return "[16]";
      break;
    case frequ::f_32:
      return "[32]";
      break;
    case frequ::f_64:
      return "[64]";
      break;
    case frequ::elements:
      return "[elements]";
      break;
  }

  return "None found!";
}
