#include "sprite.h"

Sprite::Sprite() {
   const float SIZE = 0.8f;

   GLfloat vertices[6 * 4 * 3] =
   {
      // Front
      -SIZE / 2.0f, -SIZE / 2.0f,  SIZE / 2.0f, // 0
      SIZE / 2.0f, -SIZE / 2.0f,  SIZE / 2.0f, // 1
      SIZE / 2.0f,  SIZE / 2.0f,  SIZE / 2.0f, // 2
      -SIZE / 2.0f,  SIZE / 2.0f,  SIZE / 2.0f, // 3

      // Back
      -SIZE / 2.0f, -SIZE / 2.0f, -SIZE / 2.0f, // 4
      -SIZE / 2.0f,  SIZE / 2.0f, -SIZE / 2.0f, // 5
      SIZE / 2.0f,  SIZE / 2.0f, -SIZE / 2.0f, // 6
      SIZE / 2.0f, -SIZE / 2.0f, -SIZE / 2.0f, // 7

      // Top
      -SIZE / 2.0f,  SIZE / 2.0f, -SIZE / 2.0f, // 8
      -SIZE / 2.0f,  SIZE / 2.0f,  SIZE / 2.0f, // 11
      SIZE / 2.0f,  SIZE / 2.0f,  SIZE / 2.0f, // 10
      SIZE / 2.0f,  SIZE / 2.0f, -SIZE / 2.0f, // 9

      // Bottom
      -SIZE / 2.0f, -SIZE / 2.0f, -SIZE / 2.0f, // 12
      SIZE / 2.0f, -SIZE / 2.0f, -SIZE / 2.0f, // 13
      SIZE / 2.0f, -SIZE / 2.0f,  SIZE / 2.0f, // 14
      -SIZE / 2.0f, -SIZE / 2.0f,  SIZE / 2.0f, // 15

      // Left
      -SIZE / 2.0f, -SIZE / 2.0f, -SIZE / 2.0f, // 16
      -SIZE / 2.0f, -SIZE / 2.0f,  SIZE / 2.0f, // 17
      -SIZE / 2.0f,  SIZE / 2.0f,  SIZE / 2.0f, // 18
      -SIZE / 2.0f,  SIZE / 2.0f, -SIZE / 2.0f, // 19

      // Right
      SIZE / 2.0f, -SIZE / 2.0f, -SIZE / 2.0f, // 20
      SIZE / 2.0f,  SIZE / 2.0f, -SIZE / 2.0f,  // 23
      SIZE / 2.0f,  SIZE / 2.0f,  SIZE / 2.0f, // 22
      SIZE / 2.0f, -SIZE / 2.0f,  SIZE / 2.0f // 21
   };

   GLuint indices [3 * 2] =
   {
      0, 1, 2,
      2, 3, 0
   };

   GLfloat tcs[4 * 2] =
   {
      0.0f, 1.0f,
      1.0f, 1.0f,
      1.0f, 0.0f,
      0.0f, 0.0f,
   };

   vao = new VertexArrays(vertices, indices, tcs, 4 * 3, 3 * 2);
   TEX = new Texture;
   TEX->loadTexture("resources/textures/tex.png");
}

void Sprite::render() {
   TEX->use();
   vao->render();
}
