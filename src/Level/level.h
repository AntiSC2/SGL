#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED
#include "Graphics/cube.h"
#include "Utils/fileutil.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdio.h>
#include <algorithm>

class Level {
public:
   Level(const char* levelData);
   void render();
private:
   Cube* _block;
   int _width;
   int _depth;
   int _height;
   int* _data;
};

#endif // LEVEL_H_INCLUDED
