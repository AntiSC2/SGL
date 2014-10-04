#include "texturemanager.h"

TextureManager::TextureManager() {

}

TextureManager::~TextureManager() {
   for(const auto& elem : Textures) {
      delete elem.second;
   }
   Textures.erase(Textures.begin(), Textures.end());
}

Texture* TextureManager::addTexture(std::string fileName) {
   auto it = Textures.find(fileName);
   if(it == Textures.end()) {
      Textures[fileName] = new Texture;
      it = Textures.find(fileName);
      it->second->loadTexture(fileName.c_str());
      printf("Created new Texture: %s\n", fileName.c_str());
      return it->second;
   } else {
      printf("Texture %s already existed\n", fileName.c_str());
      return it->second;
   }
}

Texture* TextureManager::findTexture(std::string fileName) {
   auto it = Textures.find(fileName);
   if(it != Textures.end()) {
      printf("Loaded cached texture\n");
      return it->second;
   } else {
      printf("Creating new texture: %s\n", fileName.c_str());
      return addTexture(fileName);
   }
}
