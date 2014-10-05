#include "shader.h"

Shader::Shader() : _numAttributes(0), _programID(0), _vertID(0), _fragID(0) {

}

Shader::~Shader() {
   if(_programID != 0)
      glDeleteProgram(_programID);
}

Shader* Shader::BASIC_RENDER = new Shader;

void Shader::compileShaders(const char* vertPath, const char* fragPath) {

   _programID = glCreateProgram();
   _vertID = glCreateShader(GL_VERTEX_SHADER);
   if(_vertID == 0)
   {
      printf("Vertex shader %s failed to be created!\n", vertPath);
   }
   _fragID = glCreateShader(GL_FRAGMENT_SHADER);
   if(_fragID == 0)
   {
      printf("Vertex shader %s failed to be created!\n", vertPath);
   }

   compileShader(vertPath, _vertID);
   compileShader(fragPath, _fragID);
}

void Shader::addAttribute(const char* attributeName) {
   glBindAttribLocation(_programID, _numAttributes++, attributeName);
}

void Shader::linkShaders() {

   glAttachShader(_programID, _vertID);
   glAttachShader(_programID, _fragID);

   glLinkProgram(_programID);

   GLint isLinked = 0;
   glGetProgramiv(_programID, GL_LINK_STATUS, (int *)&isLinked);

   if (isLinked == GL_FALSE) {
      GLint maxLength = 0;
      glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &maxLength);

      //The maxLength includes the NULL character
      std::vector<char> errorLog(maxLength);
      glGetProgramInfoLog(_programID, maxLength, &maxLength, &errorLog[0]);



      //We don't need the program anymore.
      glDeleteProgram(_programID);
      //Don't leak shaders either.
      glDeleteShader(_vertID);
      glDeleteShader(_fragID);

      //print the error log and quit
      printf("%s\n", &(errorLog[0]));
      printf("Shaders failed to link!\n");
   }

   //Always detach shaders after a successful link.
   glDetachShader(_programID, _vertID);
   glDetachShader(_programID, _fragID);
   glDeleteShader(_vertID);
   glDeleteShader(_fragID);
}


void Shader::use() {
   glUseProgram(_programID);

   for (GLuint i = 0; i < _numAttributes; i++) {
      glEnableVertexAttribArray(i);
   }
}

void Shader::unuse() {
   glUseProgram(0);
   for (GLuint i = 0; i < _numAttributes; i++) {
      glDisableVertexAttribArray(i);
   }
}

GLuint Shader::getUniformLocation(const char* uniformName) {
   GLuint location = glGetUniformLocation(_programID, uniformName);
   if(location == GL_INVALID_INDEX) {
     //printf("Uniform %s was not found in shader!", uniformName);
   }
   return location;
}


void Shader::compileShader(const char* filePath, GLuint id) {

   std::ifstream shaderFile(filePath);
   if (shaderFile.fail()) {
      printf("Failed to open %s\n", filePath);
   }

   //File contents stores all the text in the file
   std::string fileContents = "";
   //line is used to grab each line of the file
   std::string line;

   //Get all the lines in the file and add it to the contents
   while (std::getline(shaderFile, line)) {
      fileContents += line + "\n";
   }

   shaderFile.close();

   //get a pointer to our file contents c string;
   const char* contentsPtr = fileContents.c_str();
   //tell opengl that we want to use fileContents as the contents of the shader file
   glShaderSource(id, 1, &contentsPtr, nullptr);

   //compile the shader
   glCompileShader(id);

   //check for errors
   GLint success = 0;
   glGetShaderiv(id, GL_COMPILE_STATUS, &success);

   if (success == GL_FALSE) {
      GLint maxLength = 0;
      glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

      //The maxLength includes the NULL character
      std::vector<char> errorLog(maxLength);
      glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

      //Provide the infolog in whatever manor you deem best.
      //Exit with failure.
      glDeleteShader(id); //Don't leak the shader.

      //Print error log and quit
      printf("%s\n", &(errorLog[0]));
      printf("Shader failed %s to compile \n", filePath);
   }
}

void Shader::setModelMatrix(glm::mat4 trans) {
   GLuint uniModel = getUniformLocation("model");
   glUniformMatrix4fv(uniModel, 1, GL_FALSE, glm::value_ptr(trans));
}

void Shader::setViewMatrix(glm::mat4 trans) {
   GLuint uniView = getUniformLocation("view");
   glUniformMatrix4fv(uniView, 1, GL_FALSE, glm::value_ptr(trans));
}

void Shader::setProjectionMatrix(glm::mat4 trans) {
   GLuint uniProjection = getUniformLocation("projection");
   glUniformMatrix4fv(uniProjection, 1, GL_FALSE, glm::value_ptr(trans));
}


void Shader::setCameraPos(glm::vec3 pos) {
   GLuint uniCamera = getUniformLocation("camera_pos");
   glUniform3f(uniCamera, -pos.x, -pos.y, -pos.z);
}

void Shader::setModelPos(glm::vec3 pos) {
   GLuint uniModelpos = getUniformLocation("model_position");
   glUniform3f(uniModelpos, pos.x, pos.y, pos.z);
}










