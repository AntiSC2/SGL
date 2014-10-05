#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED
#ifndef GLEW_BUILD
#define GLEW_BUILD
#endif // GLEW_BUILD
#include <GL/glew.h>
#include <SDL2/SDL_image.h>

class Texture {
public:
   Texture();
   ~Texture();

   void loadTexture(const char *filePath);

   void use();
   void unuse();
   const GLuint returnID();

   static GLuint currentlyBound;

private:
   GLuint _ID;
   int _width;
   int _height;
};

#endif // TEXTURE_H_INCLUDED
