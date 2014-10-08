#include "level.h"

Level::Level(const char* levelData) {
   _width = 0;
   _depth = 0;
   _height = 1;
   _NULL_SHORT = 0;

   std::string fileData = FileUtils::read_file(levelData);
   char fileLine;
   for(int l = 0; l < fileData.size(); l++) {
      fileLine = fileData[l];
      if(fileLine == '\n') {
         _depth++;
      }
      if(_depth == 0) {
         _width++;
      }
   }

   fileData.erase(std::remove(fileData.begin(), fileData.end(), '\n'), fileData.end());

   _data = new unsigned short[_width * _depth * _height];

   for(int l = 0; l < _width * _height * _depth; l++) {
      fileLine = fileData[l];
      if(fileLine == '1') {
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

void Level::render() {
   for(int x = 0; x < _width; x++) {
      for(int y = 0; y < _depth; y++) {
         for(int z = 0; z < _height; z++) {
            if(_data[x + (y * _width) + (z * _width * _depth)] == 1)
               _block->render(glm::vec3(x + 1 + 0.5f, y + 1 + 0.5f, z + 0.5f));
         }
      }
   }
}


unsigned short& Level::get_block(glm::vec3 position) {
    position /= 1.0f;
    if (position.x < 0 || position.y < 0 || position.z < 0) return _NULL_SHORT;
    if (position.x >= _width || position.y >= _depth || position.z >= _height) return _NULL_SHORT;
    return _data[(short) position.x + ((short) position.y * _width) + ((short) position.z * _width * _depth)];

}

unsigned short& Level::raycast_collision(glm::vec3 position, glm::vec3 rotation) {
    position = -position;
    const float MAX_DISTANCE = 2.0f;
    const float ITERATION = 0.5f;
    float distance = 0.0f;
    while (distance < MAX_DISTANCE) {
        position += rotation * ITERATION;
        unsigned short &result = get_block(position);
        if (result == 1 && result != _NULL_SHORT) return result;
        distance += ITERATION;
    }
    return _NULL_SHORT;
}
