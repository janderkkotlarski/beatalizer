#include "period.h"

#include "functions.h"

int period_size()
{ return int(period::elements); }

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

float period2float(const period &peri)
{
  switch (peri)
  {
    case period::p__64:
      return 1.0f/64.0f;
      break;
    case period::p__32:
      return 1.0f/32.0f;
      break;
    case period::p__16:
      return 1.0f/16.0f;
      break;
    case period::p__8:
      return 1.0f/8.0f;
      break;
    case period::p__4:
      return 1.0f/4.0f;
      break;
    case period::p__2:
      return 1.0f/2.0f;
      break;
    case period::p_1:
      return 1.0f;
      break;
    case period::p_2:
      return 2.0f;
      break;
    case period::p_4:
      return 4.0f;
      break;
    case period::p_8:
      return 8.0f;
      break;
    case period::p_16:
      return 16.0f;
      break;
    case period::p_32:
      return 32.0f;
      break;
    case period::p_64:
      return 64.0f;
      break;
    case period::elements:
      return 0.0f;
      break;
  }

  return 0.0f;
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
