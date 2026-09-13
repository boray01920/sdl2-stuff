#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Texture.h"
#include "Camera.h"
#include "Anims.h"

#define PI 3.1415926535897

const unsigned int width = 800;
const unsigned int height = 800;


int main() {

	glfwInit();

	// GLFW version, in this case its 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(width, height, "OpenglTest", NULL, NULL); // A GLFW window object of 800x600px
	// safety check
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	

	// Vertices coordinates
	GLfloat vertices[] =
	{		//     COORDINATES     /        COLORS          /    TexCoord   /        NORMALS       //
			// Bottom face (normal: 0,-1,0)
			-0.5f, -0.5f,  0.5f,    0.83f, 0.70f, 0.44f,    0.0f, 0.0f,     0.0f, -1.0f,  0.0f,
			-0.5f, -0.5f, -0.5f,    0.83f, 0.70f, 0.44f,    0.0f, 1.0f,     0.0f, -1.0f,  0.0f,
			 0.5f, -0.5f, -0.5f,    0.83f, 0.70f, 0.44f,    1.0f, 1.0f,     0.0f, -1.0f,  0.0f,
			 0.5f, -0.5f,  0.5f,    0.83f, 0.70f, 0.44f,    1.0f, 0.0f,     0.0f, -1.0f,  0.0f,

			// Top face (normal: 0,1,0)
			 -0.5f,  0.5f,  0.5f,    0.92f, 0.86f, 0.76f,    0.0f, 0.0f,     0.0f,  1.0f,  0.0f,
			 -0.5f,  0.5f, -0.5f,    0.92f, 0.86f, 0.76f,    0.0f, 1.0f,     0.0f,  1.0f,  0.0f,
			  0.5f,  0.5f, -0.5f,    0.92f, 0.86f, 0.76f,    1.0f, 1.0f,     0.0f,  1.0f,  0.0f,
			  0.5f,  0.5f,  0.5f,    0.92f, 0.86f, 0.76f,    1.0f, 0.0f,     0.0f,  1.0f,  0.0f,

			// Front face (normal: 0,0,1)
			 -0.5f, -0.5f,  0.5f,    0.83f, 0.70f, 0.44f,    0.0f, 0.0f,     0.0f,  0.0f,  1.0f,
			  0.5f, -0.5f,  0.5f,    0.83f, 0.70f, 0.44f,    1.0f, 0.0f,     0.0f,  0.0f,  1.0f,
			  0.5f,  0.5f,  0.5f,    0.83f, 0.70f, 0.44f,    1.0f, 1.0f,     0.0f,  0.0f,  1.0f,
			 -0.5f,  0.5f,  0.5f,    0.83f, 0.70f, 0.44f,    0.0f, 1.0f,     0.0f,  0.0f,  1.0f,

			// Back face (normal: 0,0,-1)
			  0.5f, -0.5f, -0.5f,    0.83f, 0.70f, 0.44f,    0.0f, 0.0f,     0.0f,  0.0f, -1.0f,
			 -0.5f, -0.5f, -0.5f,    0.83f, 0.70f, 0.44f,    1.0f, 0.0f,     0.0f,  0.0f, -1.0f,
			  -0.5f,  0.5f, -0.5f,   0.83f, 0.70f, 0.44f,    1.0f, 1.0f,     0.0f,  0.0f, -1.0f,
			  0.5f,  0.5f, -0.5f,    0.83f, 0.70f, 0.44f,    0.0f, 1.0f,     0.0f,  0.0f, -1.0f,

			// Left face (normal: -1,0,0)
			   -0.5f, -0.5f, -0.5f,    0.83f, 0.70f, 0.44f,    0.0f, 0.0f,    -1.0f,  0.0f,  0.0f,
			   -0.5f, -0.5f,  0.5f,    0.83f, 0.70f, 0.44f,    1.0f, 0.0f,    -1.0f,  0.0f,  0.0f,
			   -0.5f,  0.5f,  0.5f,    0.83f, 0.70f, 0.44f,    1.0f, 1.0f,    -1.0f,  0.0f,  0.0f,
			   -0.5f,  0.5f, -0.5f,    0.83f, 0.70f, 0.44f,    0.0f, 1.0f,    -1.0f,  0.0f,  0.0f,
	
		   // Right face (normal: 1,0,0)
				0.5f, -0.5f,  0.5f,    0.83f, 0.70f, 0.44f,    0.0f, 0.0f,     1.0f,  0.0f,  0.0f,
				0.5f, -0.5f, -0.5f,    0.83f, 0.70f, 0.44f,    1.0f, 0.0f,     1.0f,  0.0f,  0.0f,
				0.5f,  0.5f, -0.5f,    0.83f, 0.70f, 0.44f,    1.0f, 1.0f,     1.0f,  0.0f,  0.0f,
				0.5f,  0.5f,  0.5f,    0.83f, 0.70f, 0.44f,    0.0f, 1.0f,     1.0f,  0.0f,  0.0f,
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

	GLfloat lightVertices[] =
	{ //     COORDINATES     /   TexCoord  //
		// Bottom face
		-0.1f, -0.1f,  0.1f,   0.0f, 0.0f,
		-0.1f, -0.1f, -0.1f,   1.0f, 0.0f,
		 0.1f, -0.1f, -0.1f,   1.0f, 1.0f,
		 0.1f, -0.1f,  0.1f,   0.0f, 1.0f,

		// Top face
		-0.1f,  0.1f,  0.1f,   0.0f, 0.0f,
		-0.1f,  0.1f, -0.1f,   1.0f, 0.0f,
		 0.1f,  0.1f, -0.1f,   1.0f, 1.0f,
		 0.1f,  0.1f,  0.1f,   0.0f, 1.0f,

		// Front face
		-0.1f, -0.1f,  0.1f,   0.0f, 0.0f,
		 0.1f, -0.1f,  0.1f,   1.0f, 0.0f,
		 0.1f,  0.1f,  0.1f,   1.0f, 1.0f,
	    -0.1f,  0.1f,  0.1f,   0.0f, 1.0f,

		// Back face
		 0.1f, -0.1f, -0.1f,   0.0f, 0.0f,
		-0.1f, -0.1f, -0.1f,   1.0f, 0.0f,
		-0.1f,  0.1f, -0.1f,   1.0f, 1.0f,
		 0.1f,  0.1f, -0.1f,   0.0f, 1.0f,

		// Left face
	    -0.1f, -0.1f, -0.1f,   0.0f, 0.0f,
	    -0.1f, -0.1f,  0.1f,   1.0f, 0.0f,
		-0.1f,  0.1f,  0.1f,   1.0f, 1.0f,
		-0.1f,  0.1f, -0.1f,   0.0f, 1.0f,

		// Right face
		 0.1f, -0.1f,  0.1f,   0.0f, 0.0f,
		 0.1f, -0.1f, -0.1f,   1.0f, 0.0f,
		 0.1f,  0.1f, -0.1f,   1.0f, 1.0f,
		 0.1f,  0.1f,  0.1f,   0.0f, 1.0f
	};

	GLuint lightIndices[] =
	{
		0, 1, 2,    0, 2, 3,      // Bottom
		4, 5, 6,    4, 6, 7,      // Top
		8, 9, 10,   8, 10, 11,    // Front
		12, 13, 14, 12, 14, 15,   // Back
		16, 17, 18, 16, 18, 19,   // Left
		20, 21, 22, 20, 22, 23    // Right
	};



	glfwMakeContextCurrent(window); // introduce the window to the current context

	gladLoadGL(); // load GLAD so it can configue OpenGL

	glViewport(0, 0, width, height); // In here it goes from x:0, y:0 to x:800, y:800

	Shader shaderProgram("default.vert", "default.frag");

	VAO VAO1;
	VAO1.Bind();

	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));

	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	// lighting

	Shader lightShader("light.vert", "light.frag");

	VAO lightVAO;
	lightVAO.Bind();

	VBO lightVBO(lightVertices, sizeof(lightVertices));
	EBO lightEBO(lightIndices, sizeof(lightIndices));

	lightVAO.LinkAttrib(lightVBO, 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0);
	lightVAO.LinkAttrib(lightVBO, 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3*sizeof(float)));

	lightVAO.Unbind();
	lightVBO.Unbind();
	lightEBO.Unbind();

	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

	glm::vec3 lightPos = glm::vec3(0.5f, 1.2f, 0.5f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	glm::vec3 pyramidPos = glm::vec3(0.0f, 0.5f, 0.5f);
	glm::mat4 pyramidModel = glm::mat4(1.0f);
	pyramidModel = glm::translate(pyramidModel, pyramidPos);

	lightShader.Activate();
	//glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
	glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"),lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	shaderProgram.Activate();
	//glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(pyramidModel));
	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	//glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightColor.x, lightColor.y, lightColor.z);



	// texturing

	Texture animals("neuro.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	animals.texUnit(shaderProgram, "tex0", 0);
	Texture evil("evil.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	evil.texUnit(lightShader, "tex0", 0);

	glEnable(GL_DEPTH_TEST);

	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));


	while (!glfwWindowShouldClose(window)) {

		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		camera.Inputs(window);
		camera.updateMatrix(45.0f, 0.1f, 100.0f);		

		UpdateLightAnim(lightPos, lightModel, pyramidPos, 1.0F);

		shaderProgram.Activate();
		glUniform3f(glGetUniformLocation(shaderProgram.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
		camera.Matrix(shaderProgram, "camMatrix");

		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(pyramidModel));
		glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

		animals.Bind();
		VAO1.Bind();
		glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);

		lightShader.Activate();
		camera.Matrix(lightShader, "camMatrix");

		glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
		
		evil.Bind();
		lightVAO.Bind();
		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	animals.Delete();
	shaderProgram.Delete();
	

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;

}