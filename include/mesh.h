#ifndef MESH_H
#define MESH_H

// ===============================
// AUTHOR       : Angel Ortiz (angelo12 AT vt DOT edu)
// CREATE DATE  : 2018-09-10
// PURPOSE      : TODO
// ===============================
// SPECIAL NOTES: TODO update comments
// ===============================

//Headers
#include "glm/glm.hpp"
#include "shader.h"
#include <vector>

//Beware the tale of the circular dependency!!!!
struct Vertex{
   glm::vec3 position; 
   glm::vec3 normal; 
   glm::vec2 texCoords; 
};

class Mesh {
    public:
        std::vector<Vertex> vertices;
        std::vector<unsigned int > indices;
        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices){
            this->vertices = vertices;
            this->indices  = indices ;

            setupMesh();
        }

        void draw(Shader shader);
    private:
        unsigned int VAO, VBO, EBO;

        void setupMesh();
};

#endif