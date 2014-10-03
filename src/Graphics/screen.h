#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED
#include <SDL2/SDL.h>
#ifndef GLEW_BUILD
#define GLEW_BUILD
#endif // GLEW_BUILD
#include <GL/glew.h>
#include <stdio.h>
#include "input.h"
///Screen is a class that handles the window
class Screen {
   public:
      Screen(const char *title, int width, int height);
      ~Screen();

      void clear();
      void update();

   private:

      void initGL();

      SDL_Window *_window;
      const char *_title;
      int _width;
      int _height;
};

#endif // SCREEN_H_INCLUDED
