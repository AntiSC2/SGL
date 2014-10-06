#ifndef SHADER_H_INCLUDED
#define SHADER_H_INCLUDED
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>
#ifndef GLEW_BUILD
#define GLEW_BUILD
#endif //GLEW_BUILD
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader {
   public:
      Shader();
      ~Shader();

      static Shader* BASIC_RENDER;

      void compileShaders(const char* vertPath, const char* fragPath);

      void addAttribute(const char* attributeName);

      void linkShaders();


      void use();
      void unuse();

      GLuint getUniformLocation(const char* uniformName);
      void setModelMatrix(glm::mat4 trans);
      void setViewMatrix(glm::mat4 trans);
      void setProjectionMatrix(glm::mat4 trans);
      void setCameraPos(glm::vec3 pos);
      void setModelPos(glm::vec3 pos);

   private:

      void compileShader(const char* filePath, GLuint id);

      GLuint _numAttributes;
      GLuint _programID;
      GLuint _vertID;
      GLuint _fragID;
};

#endif // SHADER_H_INCLUDED
