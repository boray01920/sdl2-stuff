// MeshData.h
#ifndef MESH_DATA_H
#define MESH_DATA_H

#include <glad/glad.h>

// ==========================================
// CUBE MESH DATA
// ==========================================
Vertex vertices[] =
{
	//               COORDINATES            /           NORMALS           /            COLORS           /       TEXTURE COORDINATES
	// Bottom face
	Vertex{glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(0.0f, -1.0f,  0.0f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, -1.0f,  0.0f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec2(0.0f, 1.0f)},
	Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(0.0f, -1.0f,  0.0f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3(0.5f, -0.5f,  0.5f), glm::vec3(0.0f, -1.0f,  0.0f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec2(1.0f, 0.0f)},

	// Top face
	Vertex{glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(0.0f,  1.0f,  0.0f), glm::vec3(0.92f, 0.86f, 0.76f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(0.0f,  1.0f,  0.0f), glm::vec3(0.92f, 0.86f, 0.76f), glm::vec2(0.0f, 1.0f)},
	Vertex{glm::vec3(0.5f,  0.5f, -0.5f), glm::vec3(0.0f,  1.0f,  0.0f), glm::vec3(0.92f, 0.86f, 0.76f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3(0.5f,  0.5f,  0.5f), glm::vec3(0.0f,  1.0f,  0.0f), glm::vec3(0.92f, 0.86f, 0.76f), glm::vec2(1.0f, 0.0f)},

	// Front face
	Vertex{glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(0.0f,  0.0f,  1.0f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(0.5f, -0.5f,  0.5f), glm::vec3(0.0f,  0.0f,  1.0f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec2(1.0f, 0.0f)},
	Vertex{glm::vec3(0.5f,  0.5f,  0.5f), glm::vec3(0.0f,  0.0f,  1.0f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(0.0f,  0.0f,  1.0f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec2(0.0f, 1.0f)},

	// Back face
	Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(0.0f,  0.0f, -1.0f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f,  0.0f, -1.0f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec2(1.0f, 0.0f)},
	Vertex{glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(0.0f,  0.0f, -1.0f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3(0.5f,  0.5f, -0.5f), glm::vec3(0.0f,  0.0f, -1.0f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec2(0.0f, 1.0f)},

	// Left face
	Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-1.0f, 0.0f,  0.0f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(-1.0f, 0.0f,  0.0f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec2(1.0f, 0.0f)},
	Vertex{glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(-1.0f, 0.0f,  0.0f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(-1.0f, 0.0f,  0.0f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec2(0.0f, 1.0f)},

	// Right face
	Vertex{glm::vec3(0.5f, -0.5f,  0.5f), glm::vec3(1.0f,  0.0f,  0.0f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(1.0f,  0.0f,  0.0f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec2(1.0f, 0.0f)},
	Vertex{glm::vec3(0.5f,  0.5f, -0.5f), glm::vec3(1.0f,  0.0f,  0.0f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3(0.5f,  0.5f,  0.5f), glm::vec3(1.0f,  0.0f,  0.0f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec2(0.0f, 1.0f)}
};

GLuint indices[] =
{
	0, 1, 2,    0, 2, 3,      // Bottom
	4, 5, 6,    4, 6, 7,      // Top
	8, 9, 10,   8, 10, 11,    // Front
	12, 13, 14, 12, 14, 15,   // Back
	16, 17, 18, 16, 18, 19,   // Left
	20, 21, 22, 20, 22, 23    // Right
};

// ==========================================
// LIGHT CUBE MESH DATA (small, position-only matters)
// ==========================================
Vertex lightVertices[] =
{
	Vertex{glm::vec3(-0.1f, -0.1f,  0.1f), glm::vec3(0.0f), glm::vec3(1.0f), glm::vec2(0.0f)},
	Vertex{glm::vec3(-0.1f, -0.1f, -0.1f), glm::vec3(0.0f), glm::vec3(1.0f), glm::vec2(0.0f)},
	Vertex{glm::vec3(0.1f, -0.1f, -0.1f), glm::vec3(0.0f), glm::vec3(1.0f), glm::vec2(0.0f)},
	Vertex{glm::vec3(0.1f, -0.1f,  0.1f), glm::vec3(0.0f), glm::vec3(1.0f), glm::vec2(0.0f)},
	Vertex{glm::vec3(-0.1f,  0.1f,  0.1f), glm::vec3(0.0f), glm::vec3(1.0f), glm::vec2(0.0f)},
	Vertex{glm::vec3(-0.1f,  0.1f, -0.1f), glm::vec3(0.0f), glm::vec3(1.0f), glm::vec2(0.0f)},
	Vertex{glm::vec3(0.1f,  0.1f, -0.1f), glm::vec3(0.0f), glm::vec3(1.0f), glm::vec2(0.0f)},
	Vertex{glm::vec3(0.1f,  0.1f,  0.1f), glm::vec3(0.0f), glm::vec3(1.0f), glm::vec2(0.0f)}
};

GLuint lightIndices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
};

#endif