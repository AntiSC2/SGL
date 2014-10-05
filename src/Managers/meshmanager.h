#ifndef MESHMANAGER_H_INCLUDED
#define MESHMANAGER_H_INCLUDED

#include <string>
#include <map>
#include "Utils/vertexarrays.h"

class MeshManager
{
public:
   MeshManager();
   ~MeshManager();
   VertexArrays* findMesh(std::string fileName);
   void removeMesh(std::string fileName);
private:
   VertexArrays* addMesh(std::string fileName);
   std::map<std::string, VertexArrays*> meshes;
};

#endif // MESHMANAGER_H_INCLUDED
