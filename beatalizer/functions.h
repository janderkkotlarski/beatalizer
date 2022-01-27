#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

#include "raylib.h"

#include "auronacci.h"

enum class trigon;

enum class movement;

enum class dimension;

enum class coloring;

int half_int(const int number);

unsigned char unchar(const float input);

Vector3 orbit_pos(const Vector3 &pos, const Vector3 &dir,
               const float dist, const float phase);

#endif // FUNCTIONS_H
