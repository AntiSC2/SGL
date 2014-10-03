#include "vertexarrays.h"

VertexArrays::VertexArrays(GLfloat *vertices, GLuint *indices, GLsizei vcount, GLsizei icount) {
   this->count = icount;
   vao = compile(vertices, indices, nullptr, vcount, icount);
}

VertexArrays::VertexArrays(GLfloat *vertices, GLuint *indices, GLfloat *tcs, GLsizei vcount, GLsizei icount) {
   this->count = icount;
   vao = compile(vertices, indices, tcs, vcount, icount);
}

VertexArrays::~VertexArrays() {
   this->count = 0;
   if(vao != 0) {
      glDeleteVertexArrays(1, &vao);
   }
}

GLuint VertexArrays::compile(GLfloat *vertices, GLuint *indices, GLfloat *tcs, GLsizei vcount, GLsizei icount) {
   GLuint vao, tbo, vbo;

   glGenVertexArrays(1, &vao);
   glBindVertexArray(vao);

   glGenBuffers(1, &vbo);
   glBindBuffer(GL_ARRAY_BUFFER, vbo);
   glBufferData(GL_ARRAY_BUFFER, vcount * sizeof(GLfloat), vertices, GL_STATIC_DRAW);
   glEnableVertexAttribArray(0);
   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
   glBindBuffer(GL_ARRAY_BUFFER, 0);

   /*GLubyte cat[4 * 4] = {
      0, 255, 0, 255,//Top-left
      255, 0, 0, 255,//Bottom-left
      0, 0, 255, 255,//Bottom-right
      255, 255, 0, 255   //Top-right
   };*/
   glGenBuffers(1, &tbo);
   glBindBuffer(GL_ARRAY_BUFFER, tbo);
   glBufferData(GL_ARRAY_BUFFER, vcount * sizeof(GLfloat), tcs, GL_STATIC_DRAW);
   glEnableVertexAttribArray(2);
   glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);
   glBindBuffer(GL_ARRAY_BUFFER, 0);


   glGenBuffers(1, &ibo);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
   glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), indices, GL_STATIC_DRAW);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

   glBindVertexArray(0);

   return vao;
}

void VertexArrays::render() {
   glBindVertexArray(vao);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
   glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
   glBindVertexArray(0);
}
