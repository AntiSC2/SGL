#include "cube.h"

Cube::Cube() {
   vao = RM::MeshCache->findMesh("resources/models/Cube.obj");
   TEX = RM::TextureCache->findTexture("resources/textures/tex.png");
}

Cube::~Cube() {
   vao = nullptr;
   TEX = nullptr;
}

void Cube::render(glm::vec3 position) {
   glm::mat4 model = glm::translate(glm::mat4(1.0f), position);
   Shader::BASIC_RENDER->setModelMatrix(model);
   Shader::BASIC_RENDER->setModelPos(position);
   TEX->use();
   vao->render();
}










