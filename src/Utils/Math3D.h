#ifndef MATH3D_H_INCLUDED
#define MATH3D_H_INCLUDED
#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Math {
public:
   static float to_radians(float degrees) {
      return degrees * 3.14 / 180.0f;
   }
   static bool precise(float a, float b){
      if(abs(a) - abs(b) < 0.000001f){
         return true;
      }
      return false;
   }
};

#endif // MATH3D_H_INCLUDED
