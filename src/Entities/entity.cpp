#include "entity.h"

Entity::Entity() {

}

Entity::~Entity() {
   //delete vao;
}

glm::vec3 Entity::get_position() {
   return position;
}
