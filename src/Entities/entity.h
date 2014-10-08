#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Level/level.h"

class Entity {
   public:
      Entity();
      ~Entity();
      glm::vec3 get_position();
      virtual void update(Level *level) = 0;
      virtual void render() = 0;
   protected:
      // VertexArrays *vao;
      glm::vec3 position;
};

#endif // ENTITY_H_INCLUDED
