#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "entity.h"
#include "Graphics/shader.h"
#include "input.h"
#include "Utils/Math3D.h"

class Player : public Entity {
public:
   Player(glm::vec3 position);

   void update();
   void render();
private:
   glm::vec3 rotation;
   float mouse_sensitivity = 0.2f;
   float speed = 0.05;
};

#endif // PLAYER_H_INCLUDED
