#include "cube.h"

Cube::Cube() {
   const float SIZE = 0.5f;
   GLfloat vertices[6 * 4 * 3] = {
      // Front
      -SIZE, -SIZE ,  SIZE , // 0
      SIZE , -SIZE ,  SIZE , // 1
      SIZE ,  SIZE ,  SIZE , // 2
      -SIZE ,  SIZE ,  SIZE , // 3

      // Back
      -SIZE , -SIZE , -SIZE , // 4
      -SIZE ,  SIZE , -SIZE , // 5
      SIZE ,  SIZE , -SIZE , // 6
      SIZE , -SIZE , -SIZE , // 7

      // Top
      -SIZE ,  SIZE , -SIZE , // 8
      -SIZE ,  SIZE ,  SIZE , // 11
      SIZE ,  SIZE ,  SIZE , // 10
      SIZE ,  SIZE , -SIZE , // 9

      // Bottom
      -SIZE , -SIZE , -SIZE , // 12
      SIZE , -SIZE , -SIZE , // 13
      SIZE , -SIZE ,  SIZE , // 14
      -SIZE , -SIZE ,  SIZE , // 15

      // Left
      -SIZE , -SIZE , -SIZE , // 16
      -SIZE , -SIZE ,  SIZE , // 17
      -SIZE ,  SIZE ,  SIZE , // 18
      -SIZE ,  SIZE , -SIZE , // 19

      // Right
      SIZE , -SIZE , -SIZE , // 20
      SIZE ,  SIZE , -SIZE ,  // 23
      SIZE ,  SIZE ,  SIZE , // 22
      SIZE , -SIZE ,  SIZE  // 21
   };

   GLuint indices[6 * 6] = {
      0,  1,  2,  2,  3,  0, // Front
      4,  5,  6,  6,  7,  4, // Back
      8,  9, 10, 10, 11,  8, // Top
      12, 13, 14, 14, 15, 12, // Bottom
      16, 17, 18, 18, 19, 16, // Left
      20, 21, 22, 22, 23, 20  // Right
   };

   GLfloat tcs[4 * 6 * 2] = {
      0.0f, 1.0f,
      1.0f, 1.0f,
      1.0f, 0.0f,
      0.0f, 0.0f,

      0.0f, 1.0f,
      1.0f, 1.0f,
      1.0f, 0.0f,
      0.0f, 0.0f,

      0.0f, 1.0f,
      1.0f, 1.0f,
      1.0f, 0.0f,
      0.0f, 0.0f,

      0.0f, 1.0f,
      1.0f, 1.0f,
      1.0f, 0.0f,
      0.0f, 0.0f,

      0.0f, 1.0f,
      1.0f, 1.0f,
      1.0f, 0.0f,
      0.0f, 0.0f,

      0.0f, 1.0f,
      1.0f, 1.0f,
      1.0f, 0.0f,
      0.0f, 0.0f
   };
   vao = new VertexArrays(vertices, indices, tcs, 6 * 4 * 3, 6 * 6);
   TEX = RM::TextureCache->findTexture("resources/textures/tex.png");
}

Cube::~Cube() {
   delete vao;
   TEX = nullptr;
}

void Cube::render(glm::vec3 position) {
   glm::mat4 model = glm::translate(glm::mat4(1.0f), position);
   Shader::BASIC_RENDER->setModelMatrix(model);

   TEX->use();
   vao->render();
}










