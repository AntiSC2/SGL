#ifndef RESOURCEMANAGER_H_INCLUDED
#define RESOURCEMANAGER_H_INCLUDED
#include <map>
#include "Utils\vertexarrays.h"
#include <stdio.h>
#include "texturemanager.h"

class RM {
   public:
      static TextureManager *TextureCache;
   private:
      RM() {}
};



#endif // RESOURCEMANAGER_H_INCLUDED
