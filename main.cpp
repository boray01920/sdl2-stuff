#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Texture.h"


int main() {

	glfwInit(); // initializes GLFW

	// GLFW versions we are using, in this case its 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Tell GLFW that we are using the CORE profile, we only have the modern functions

	GLFWwindow* window = glfwCreateWindow(800, 800, "OpenglTest", NULL, NULL); // A GLFW window object of 800x600px, named "OpenglTest". Rest is unimportant
	// safety check
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	GLfloat vertices[] = {
	//  COORDINATES                  COLORS
		-0.5f, -0.5f, 0.0f,		 1.0f, 0.0f, 0.0f,	0.0f, 0.0f,	// bottom left  - red
		 0.5f, -0.5f, 0.0f,		 0.0f, 1.0f, 0.0f,	1.0f, 0.0f,	// bottom right - green
		 0.5f,  0.5f, 0.0f,		 0.0f, 0.0f, 1.0f,	1.0f, 1.0f,	// top right    - blue
		-0.5f,  0.5f, 0.0f,		 1.0f, 1.0f, 0.0f,	0.0f, 1.0f  // top left     - yellow
	};

	GLuint indices[] = {
		0,1,2,
		2,3,0
	};

	glfwMakeContextCurrent(window); // introduce the window to the current context

	gladLoadGL(); // load GLAD so it can configue OpenGL

	glViewport(0, 0, 800, 800); // In here it goes from x:0, y:0 to x:800, y:800

	Shader shaderProgram("default.vert", "default.frag");

	VAO VAO1;
	VAO1.Bind();

	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));

	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");


	Texture animals("animals.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	animals.texUnit(shaderProgram, "tex0", 0);


	while (!glfwWindowShouldClose(window)) {

		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		shaderProgram.Activate();
		glUniform1f(uniID, 0.5f);
		animals.Bind();
		VAO1.Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
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