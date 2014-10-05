#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED
#include "Utils/vertexarrays.h"
#include "Graphics/texture.h"
#ifndef GLEW_BUILD
#define GLEW_BUILD
#endif // GLEW_BUILD
#include <GL/glew.h>

class Sprite {
public:
   Sprite();
   void render();
private:
   VertexArrays *vao;
   Texture *TEX;
};


#endif // SPRITE_H_INCLUDED
