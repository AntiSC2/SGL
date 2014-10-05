#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

class Level {
public:
   Level(const char* levelData);
   void render();
private:
   int _width;
   int _height;
};

#endif // LEVEL_H_INCLUDED
