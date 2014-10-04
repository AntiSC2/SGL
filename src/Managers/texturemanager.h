#ifndef TEXTUREMANAGER_H_INCLUDED
#define TEXTUREMANAGER_H_INCLUDED
#ifndef GLEW_BUILD
#define GLEW_BUILD
#endif // GLEW_BUILD
#include <GL/glew.h>
#include <map>
#include "Graphics/texture.h"
#include <stdio.h>
#include <string>

class TextureManager {
   public:
      TextureManager();
      ~TextureManager();
      Texture* findTexture(std::string fileName);
      void   removeTexture();
   private:
      std::map<std::string, Texture*> Textures;
      Texture* addTexture(std::string fileName);
};

#endif // TEXTUREMANAGER_H_INCLUDED
