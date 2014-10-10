#include "camera2D.h"

Camera2D::Camera2D() : width(1280), height(720),scale(1), position(0.0f, 0.0f), cameraMatrix(1), orthoMatrix(glm::ortho(0.0f, (float)width, 0.0f, (float)height)) needMatrixUpdate(1){
   ;
}

Camera2D::~Camera2D(){
   ;
}

void Camera2D::initScreenCoord(int width, int height){
   this->width = width;
   this->height = height;
   orthoMatrix = glm::ortho(0.0f, (float)width, 0.0f, (float)height)
}


void Camera2D::update(){
   if(needMatrixUpdate){
      glm::vec3 translate(-position.x, -position.y, 0.0f);
      cameraMatrix = glm::translate(orthoMatrix, -position);
      glm::vec3 scaleV(scale, scale, 0.0f);
      cameraMatrix = glm::scale(scaleV, scaleV, 0.0f);
   }
}

void Camera2D::setPosition(const glm::vec2& position){
   this->position = position;
}

void Camera2D::setScale(float scale){
   this->scale = scale;
}

glm::vec2 Camera2D::getPosition(){
   return this->position;
}

float Camera2D::getScale(){
   return this->scale;
}

glm::mat4 Camera2D::(){
   return this->cameraMatrix;
}
