#include "player.h"

Player::Player(glm::vec3 position) {
   this->position = position;
   this->rotation = glm::vec3(0.0f, 0.0f, 0.0f);
}

void Player::render() {
   glm::mat4 vw_matrix = glm::rotate(glm::mat4(1.0f), rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
   vw_matrix *= glm::rotate(glm::mat4(1.0f), rotation.y, glm::vec3(0.0f, 0.0f, 1.0f));
   vw_matrix *= glm::translate(glm::mat4(1.0f), position);
   Shader::BASIC_RENDER->setViewMatrix(vw_matrix);
}

void Player::update() {
   if (Input::key_pressed(SDL_SCANCODE_W)) {
      float xa = cos(Math::to_radians(rotation.y+90.0f)) * speed;
      float ya = -sin(Math::to_radians(rotation.y+90.0f)) * speed;
      //float za = -sin(Math::to_radians(rotation.x)) * speed;

      position.x += xa;
      position.y += ya;
      //position.z += za;
   }
   if (Input::key_pressed(SDL_SCANCODE_S)) {
      float xa = -cos(Math::to_radians(rotation.y+90.0f)) * speed;
      float ya = sin(Math::to_radians(rotation.y+90.0f)) * speed;

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
   if (Input::mouse_grabbed()) {
      rotation.x -= Input::get_DY() * mouse_sensitivity;
      rotation.y -= Input::get_DX() * mouse_sensitivity;
   }
   if (rotation.y < -90.0f) rotation.y = -90.0f;
   if (rotation.y >  90.0f) rotation.y =  90.0f;
}
