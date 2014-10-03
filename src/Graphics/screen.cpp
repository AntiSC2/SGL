#include "screen.h"

//The constructor
Screen::Screen(const char *title, int width, int height) : _title(title), _width(width), _height(height) {
   //Creates the window and initializes OpenGL
   _window = SDL_CreateWindow(_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _width, _height, SDL_WINDOW_OPENGL);

   if(_window == nullptr) {

      printf("Could not create window! SDL Error: %s", SDL_GetError());

   }

   initGL();
}

Screen::~Screen() {
   SDL_DestroyWindow(_window);
   _window = nullptr;
}


void Screen::clear() {
   glClearDepth(10.0f);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Screen::update() {
   GLenum err;
   while ((err = glGetError()) != GL_NO_ERROR) {
      //printf("Error while rendering! GLEW ERROR: %s\n", glGetString(err));
   }

   SDL_GL_SwapWindow(_window);
}

void Screen::initGL() {

   //Sets some basic OpenGL attributes
   SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3);
   SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3);
   SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );
   SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 3);
   SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);


   if(SDL_GL_CreateContext(_window) == nullptr) {
      printf("Could not create OpenGL context! SDL Error: %s", SDL_GetError());
   }

   GLenum err = glewInit();

   if(err != GLEW_OK) {
      printf("Could not initialize GLEW! GLEW ERROR: %s", glewGetErrorString(err));
   } else {

      printf("OpenGL Version %s\n", glGetString(GL_VERSION));

      glEnable(GL_DEPTH_TEST);
      glEnable (GL_BLEND);
      glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

      glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

   }
}

SDL_Window* Screen::getWindow() {
   return _window;
}

int Screen::getHeight(){
   return _height;
}

int Screen::getWidth(){
   return _width;
}

