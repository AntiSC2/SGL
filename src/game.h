#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "Graphics/screen.h"
#include "Graphics/shader.h"
#include <fstream>
#include <stdio.h>
#include <string>
#include "Graphics/sprite.h"
#include <SDL2/SDL_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <time.h>
#include "Graphics/cube.h"
#include "input.h"
#include "Entities/player.h"
#include "Managers/resourcemanager.h"
#include "Utils/fileutil.h"
#include <vector>




///Handles the entire game
class Game {
   public:
      ///Constructor for game and screen class and simple destructor
      Game(const char* title, int win_w, int win_h);
      ~Game();
      ///Contains the gameloop and calls the other functions during runtime.
      void run();
      ///Loads in resources like textures, sound, shaders and other things needed.
      static void initSystems();
      static void loadResources(const char *data);

   private:
      //Updates the game
      void update();
      //Draws the scene to the window
      void render();
      //Inits the shaders
      void initShaders();
      //The window is handled by it's own class
      Screen _screen;
      std::vector<Cube*> cubes;
      Input input;
      Player player;
};

#endif // GAME_H_INCLUDED
