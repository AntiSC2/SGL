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
      unsigned short& raycast_collision(glm::vec3 position, glm::vec3 rotation, bool returnZ = false);
      unsigned short& get_block(glm::vec3 position, bool returnZ = false);
      float raycast_actualZ(glm::vec3 position, glm::vec3 rotation);
   private:
      Cube* _block;
      int _width;
      int _depth;
      unsigned short _NULL_SHORT;
      int _height;
      unsigned short* _data;
      unsigned short _maxZlevel;
};

#endif // LEVEL_H_INCLUDED
