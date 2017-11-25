#ifndef __GAMETYPES_H__
#define __GAMETYPES_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>
#include <algorithm>

struct Vect2_t
{
  float x;
  float y;
};
Vect2_t operator+=(Vect2_t& lhs, Vect2_t& rhs)
{
  lhs.x += rhs.x;
  lhs.y += rhs.y;
}
Vect2_t operator-=(Vect2_t& lhs, Vect2_t& rhs)
{
  lhs.x -= rhs.x;
  lhs.y -= rhs.y;
}

struct Vect3_t
{
  float x;
  float y;
  float z;
};
Vect3_t operator+=(Vect3_t& lhs, Vect3_t& rhs)
{
  lhs.x += rhs.x;
  lhs.y += rhs.y;
  lhs.z += rhs.z;
}
Vect3_t operator-=(Vect3_t& lhs, Vect3_t& rhs)
{
  lhs.x -= rhs.x;
  lhs.y -= rhs.y;
  lhs.z -= rhs.z;
}

struct Forces2d_t
{
  float gravity;

  Vect2_t wind;

  Vect2_t friction;
  
};

#endif // __GAMETYPES_H__
