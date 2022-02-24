#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>

#include "raylib.h"

#include "auronacci.h"

enum class trigon;

enum class movement;

enum class dimension;

enum class coloring;

int half_int(const int number);

unsigned char unchar(const float input);

Vector3 random_pos_auro(auronacci &gold);

void normandicular(Vector3 &pos_x, Vector3 &pos_y, Vector3 &pos_z);

Vector3 orbit_pos(const Vector3 &pos, const Vector3 &dir,
                  const float dist, const float phase);

void orbit_jump(Vector3 &pos, Vector3 &dir, const float phase);

std::vector <int> color2ints(const Color &color);

#endif // FUNCTIONS_H
