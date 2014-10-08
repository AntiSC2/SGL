#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "entity.h"
#include "Graphics/shader.h"
#include "input.h"
#include "Utils/Math3D.h"
//#include "Level/level.h"

class Player : public Entity {
   public:
      Player(glm::vec3 position);

      void update(Level *level);
      void render();
   private:
      glm::vec3 rotation;
      float mouse_sensitivity = 0.2f;
      float speed = 0.08;
      bool jumping;
      float jumpingHeight;
      float fallingSpeed;
};

#endif // PLAYER_H_INCLUDED
