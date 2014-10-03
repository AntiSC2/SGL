#ifndef CUBE_H_INCLUDED
#define CUBE_H_INCLUDED
#ifndef GLEW_BUILD
#define GLEW_BUILD
#endif // GLEW_BUILD
#include <gl/glew.h>
#include "Utils/vertexarrays.h"
#include "Graphics/texture.h"
#include "Graphics/shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Cube {
   public:
      Cube();
      ~Cube();
      void render(glm::vec3 position);
   private:
      VertexArrays *vao;
      Texture *TEX;
};

#endif // CUBE_H_INCLUDED
