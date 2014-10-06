#ifndef FILEUTIL_H_INCLUDED
#define FILEUTIL_H_INCLUDED

#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdexcept>

class FileUtils {
   public:
      static std::string read_file(const char *filename) {
         std::string result;
         std::ifstream stream(filename, std::ios::in);
         if (!stream.good()) {
            printf("File '%s' doesn't exist!", filename);
            return NULL;
         }
         if (!stream.is_open()) {
            throw new std::runtime_error("Could not read file: " + std::string(filename));
         }
         std::string line = "";
         while (!stream.eof()) {
            std::getline(stream, line);
            result += line + "\n";
         }
         printf("Loaded file: '%s'\n", filename);
         stream.close();
         return result;
      }
};

#endif // FILEUTIL_H_INCLUDED
