#include "texture.h"


Texture::Texture() : _ID(0), _width(0), _height(0) {

}

Texture::~Texture() {
   if(_ID != 0) {
      glDeleteTextures(1, &_ID);
   }
}

GLuint Texture::currentlyBound = 0;

void Texture::loadTexture(const char *filePath) {
   if(_ID != 0) {
      glDeleteTextures(1, &_ID);
   }
   //Generating the texture itself
   glGenTextures(1, &_ID);
   glBindTexture(GL_TEXTURE_2D, _ID);
   //Specify simple parameters
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

   //Generate the mip map
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
   //Loading in the image
   SDL_Surface *surface = IMG_Load(filePath);
   if(surface == nullptr || surface == NULL) {
      printf("Failed to load image file %s!\n", filePath);
      printf("Could not create texture! Missing Image!\n");
   }
   //Upload the data to the GPU
   _width = surface->w;
   _height = surface->h;
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surface->pixels);
   //Create mipmap for the texture
   glGenerateMipmap(GL_TEXTURE_2D);
   //Clean up
   printf("ID TEXTURE:%u ", _ID);
   SDL_FreeSurface(surface);
   glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::use() {
   if(currentlyBound != _ID) {
      glBindTexture(GL_TEXTURE_2D, _ID);
      currentlyBound = _ID;
   }
}

void Texture::unuse() {
   glBindTexture(GL_TEXTURE_2D, 0);
   currentlyBound = 0;
}
