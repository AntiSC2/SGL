#ifndef CAMERA2D_H_INCLUDED
#define CAMERA2D_H_INCLUDED
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera2D {
   public:
      Camera2D();
      ~Camera2D();

      void initScreenCoord(int width, int height);

      void update();

      void setPosition(const glm::vec2& position);
      void setScale(float scale);

      glm::vec2 getPosition();
      float getScale();
      glm::mat4 getCameraMatrix();

   private:
      int width, height;
      bool needMatrixUpdate;
      float scale;
      glm::vec2 position;
      glm::mat4 cameraMatrix;
      glm::mat4 orthoMatrix;
};


#endif // CAMERA2D_H_INCLUDED
