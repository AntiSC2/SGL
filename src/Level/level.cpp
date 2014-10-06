#include "level.h"

Level::Level(const char* levelData){
   _width = 0;
   _depth = 0;
   _height = 1;

   std::string fileData = FileUtils::read_file(levelData);
   char fileLine;
   for(int l = 0; l < fileData.size(); l++){
      fileLine = fileData[l];
      if(fileLine == '\n'){
         _depth++;
      }
      if(_depth == 0){
         _width++;
      }
   }

   fileData.erase(std::remove(fileData.begin(), fileData.end(), '\n'), fileData.end());

   _data = new int[_width * _depth * _height];

   for(int l = 0; l < _width * _height * _depth; l++){
      fileLine = fileData[l];
      if(fileLine == '1'){
         _data[l] = 1;
         //printf("%d", _data[l]);
      } else if(fileLine == '0') {
         //_data[l] = 0;
         printf("%d", _data[l]);
      } else {
         //printf("\n");
      }

   }

   _block = new Cube;
}

void Level::render(){
   for(int x = 0; x < _width; x++){
      for(int y = 0; y < _depth; y++){
         for(int z = 0; z < _height; z++){
            if(_data[x + (y * _width) + (z * _width * _depth)] == 1)
               _block->render(glm::vec3(x + 1, y + 1, z));
         }
      }
   }
}
