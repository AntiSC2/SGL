#ifndef VERTEXARRAYS_H_INCLUDED
#define VERTEXARRAYS_H_INCLUDED
#ifndef GLEW_BUILD
#define GLEW_BUILD
#endif // GLEW_BUILD
#include <GL/glew.h>
#include <stdio.h>

class VertexArrays {
   public:
      VertexArrays(GLfloat *vertices, GLuint *indices, GLsizei vcount, GLsizei icount);
      VertexArrays(GLfloat *vertices, GLuint *indices, GLfloat *tcs, GLsizei vcount, GLsizei icount);
      ~VertexArrays();
      void render();
   private:

      GLuint vao;
      GLuint ibo;
      GLsizei count;
      GLuint compile(GLfloat *vertices, GLuint *indices, GLfloat *tcs, GLsizei vcount, GLsizei icount);
};

#endif // VERTEXARRAYS_H_INCLUDED
