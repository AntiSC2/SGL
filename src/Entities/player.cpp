#include "player.h"

Player::Player(glm::vec3 position) {
   this->position.x = - position.x;
   this->position.y = - position.y;
   this->position.z = - position.z;
}

void Player::render() {
   glm::mat4 vw_matrix = glm::rotate(glm::mat4(1.0f), rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
   vw_matrix *= glm::rotate(glm::mat4(1.0f), rotation.y, glm::vec3(0.0f, 0.0f, 1.0f));
   vw_matrix *= glm::translate(glm::mat4(1.0f), position);
   Shader::BASIC_RENDER->setViewMatrix(vw_matrix);
   Shader::BASIC_RENDER->setCameraPos(position);
}

void Player::update() {
   if (Input::key_pressed(SDL_SCANCODE_W)) {
      float xa = cos(Math::to_radians(rotation.y + 90.0f)) * speed;
      float ya = -sin(Math::to_radians(rotation.y + 90.0f)) * speed;
      position.x += xa;
      position.y += ya;
   }
   if (Input::key_pressed(SDL_SCANCODE_S)) {
      float xa = -cos(Math::to_radians(rotation.y + 90.0f)) * speed;
      float ya = sin(Math::to_radians(rotation.y + 90.0f)) * speed;
      position.x += xa;
      position.y += ya;
   }
   if (Input::key_pressed(SDL_SCANCODE_A)) {
      float xa = cos(Math::to_radians(rotation.y)) * speed;
      float ya = -sin(Math::to_radians(rotation.y)) * speed;
      position.x += xa;
      position.y += ya;
   }
   if (Input::key_pressed(SDL_SCANCODE_D)) {
      float xa = -cos(Math::to_radians(rotation.y)) * speed;
      float ya = sin(Math::to_radians(rotation.y)) * speed;
      position.x += xa;
      position.y += ya;
   }
   if (Input::key_pressed(SDL_SCANCODE_J)) {
      position.z -= 0.05f;
   }
   if (Input::key_pressed(SDL_SCANCODE_K)) {
      position.z += 0.05f;
   }
   if (Input::key_pressed(SDL_SCANCODE_R)){
      position.z = -2.0f;
      position.x = -5.0f;
      position.y = -5.0f;
   }
   if (Input::key_pressed(SDL_SCANCODE_SPACE)){
      if(Math::precise(position.z, 2.0f)){
         fallingSpeed = -0.2;
      }
   }
   if (Input::mouse_grabbed()) {
      rotation.x -= Input::get_DY() * mouse_sensitivity;
      rotation.y -= Input::get_DX() * mouse_sensitivity;
   }
   if (rotation.x < -175.0f) rotation.x = -175.0f;
   if (rotation.x >  -5.0f) rotation.x =  -5.0f;

   if((position.x > -0.1 || position.x < -16.9) || (position.y > -0.1 || position.y < -16.9) || (position.z > -0.5)){
      fallingSpeed += 0.00982f;
   } else if(position.z > -2.0f){
      fallingSpeed = 0;
      position.z = -2.0f;
   } else if(position.z < -2.0f){
      fallingSpeed += 0.00982f;
   }
   position.z += fallingSpeed;
}
