#include "game.h"
//The constructor passes the data to the screen
Game::Game(const char* title, int win_w, int win_h) : _screen(title, win_w, win_h), player(glm::vec3(5.0f, 5.0f, 2.0f)) {

}
//The destructor quits SDL and it's subsystems
Game::~Game() {
   delete Shader::BASIC_RENDER;
   for(int i = 0; i < cubes.size(); i++)
   {
      delete cubes[i];
   }
   delete RM::TextureCache;
   IMG_Quit();
   SDL_Quit();
   // NOTE (Anti#9#): Remember to free the memory from the managers later ...
}


//Handles the game
void Game::run() {
   initShaders();
   cubes.push_back(new Cube);
   cubes.push_back(new Cube);
   cubes.push_back(new Cube);
   cubes.push_back(new Cube);
   cubes.push_back(new Cube);
   cubes.push_back(new Cube);
   cubes.push_back(new Cube);
   cubes.push_back(new Cube);
   cubes.push_back(new Cube);
   cubes.push_back(new Cube);
   cubes.push_back(new Cube);
   cubes.push_back(new Cube);
   cubes.push_back(new Cube);
   cubes.push_back(new Cube);
   cubes.push_back(new Cube);
   cubes.push_back(new Cube);

   //How much to delay the update function in milliseconds, 16 milliseconds ~ 60 updates per second
   const double dt = 16.66666666666;
   //Varibles to keep track of time
   long double currentTime = SDL_GetTicks();
   long double newTime;
   //How long the frame lasted
   long double frameTime = 0;
   //Accumulates the frametimes
   long double accumulator = 0;
   //Timer that handles output of updates and frames
   uint32_t timer = SDL_GetTicks();
   //Keeps track of how many updates and frames the loop goes through before 1 second
   uint16_t updates = 0;
   uint16_t frames = 0 ;
   //A while loop to repeat the update and render functions
   while(!input.window_closed()) {
      //Calculates the frametime by taking the current time and subtract it by the oldtime to see how long the previous frame was
      newTime = SDL_GetTicks();
      frameTime = newTime - currentTime;
      currentTime = newTime;
      //Add the frameTime to the accumulator
      accumulator += frameTime;
      //If frame time has become larger than 16 milliseconds
      while(accumulator >= dt) {
         update();
         accumulator -= dt;
         updates++;

      }
      //Render the scene
      render();
      frames++;
      //If one second has passed, output the fps and updates
      if(SDL_GetTicks() - timer >= 1000) {
         printf("\nUpdates: %u\nFrames: %u\nCamera position: x = %f, y = %f, z = %f", updates, frames, player.get_position().x, player.get_position().y, player.get_position().z);
         timer = SDL_GetTicks();
         frames = 0;
         updates = 0;
      }
   }
}

void Game::initSystems() {
   //The file to read data from
   //If it could not open the file don't initialize the program
   if(SDL_Init(SDL_INIT_VIDEO) != 0) {
      //Prints an error if SDL failed to initialize!
      printf("Could not initialize SDL! SDL Error: %s", SDL_GetError());

   }
   else if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
      //Prints an error if SDL_image failed to initialize!
      printf("SDL_image could not initialize! SDL Error: %s", IMG_GetError());
   }
}

//Load resources, The data file must be in this order: Shaders, textures
void Game::loadResources(const char* data) {
   //Loads the files here
   bool textures = false;
   bool levels = false;
   bool models = false;
   std::string fileData = FileUtils::read_file(data);
   std::string fileLine;
   for(int i = 0; i < fileData.size(); i++) {
      if(fileData[i] != '\n') {
         fileLine += fileData[i];
      }
      else
      {
         if(fileLine == "Textures") {
            models = false;
            textures = true;
            levels = false;
         }
         else if(fileLine == "Levels") {
            models = false;
            textures = false;
            levels = true;
         }
         else if(fileLine == "Models") {
            models = true;
            textures = false;
            levels = false;
         }
         else if(textures == true) {
            RM::TextureCache->findTexture(fileLine);
         } else if(models == true) {
            RM::MeshCache->findMesh(fileLine);
         }
         fileLine = "";
      }
   }
}


//Updates the position of things
void Game::update() {
   input.update();
   player.update();


   if(Input::mouse_grabbed())
   {
      SDL_WarpMouseInWindow(_screen.getWindow(), _screen.getWidth() / 2, _screen.getHeight() / 2);
   }

}
//Clears and render the new scene
void Game::render() {
   _screen.clear();

   player.render();
   for(int x = 0; x < cubes.size(); x++)
   {
      for(int y = 0; y < cubes.size(); y++)
      {
         cubes[x]->render(glm::vec3(x * 1.0 + 1, y * 1.0 + 1, 0.0f));
      }
   }

   _screen.update();
}


void Game::initShaders() {
   Shader::BASIC_RENDER->compileShaders("resources/shaders/Render.vert", "resources/shaders/Render.frag");
   Shader::BASIC_RENDER->addAttribute("position");
   Shader::BASIC_RENDER->addAttribute("texcoord");
   Shader::BASIC_RENDER->linkShaders();
   Shader::BASIC_RENDER->use();
   glm::mat4 proj;
   proj = glm::perspective(80.0f, 1280.0f / 720.0f, 0.1f, 1000.0f);
   Shader::BASIC_RENDER->setProjectionMatrix(proj);
}





