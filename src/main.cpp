#include "game.h"
#include "Graphics/shader.h"

int main(int argc, char **argv) {
   //Loads in the game resources
   Game::initSystems();
   //Creates the game class and window
   Game g("WHAT IS GOING ON???", 1280, 720);
   Game::loadResources("resources\\data\\Game.data");
   //Temp code
   /*std::string fileData = "resources/shaders/Render.vert";
   Shader::BASIC_RENDER->compileShaders(fileData.c_str(), "resources/shaders/Render.frag");
   //Shader::BASIC_RENDER->addAttribute("position");
   Shader::BASIC_RENDER->linkShaders();
   GLuint vao;
   glGenVertexArrays(1, &vao);
   glBindVertexArray(vao);
   Shader::BASIC_RENDER->use();*/

   //Runs the game
   g.run();
   //Returns 0 if sucessful
   return 0;
}
