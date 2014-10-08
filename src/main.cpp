#include "game.h"
#include "Graphics/shader.h"
#include <iostream>

int main(int argc, char **argv) {
   //Loads in the game resources
   Game::initSystems();
   //Creates the game class and window
   Game g("WHAT IS GOING ON???", 1280, 720);
   Game::loadResources("resources\\data\\Game.data");
   //Runs the game
   g.run();
   //Returns 0 if sucessful
   return 0;
}
