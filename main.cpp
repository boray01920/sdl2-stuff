#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"


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
		0.0f, 0.7f, 0.0f, //0
		0.4f, 0.4f, 0.0f, //1
		0.7f, 0.4f, 0.0f, //2
		0.6f, 0.0f, 0.0f, //3
		0.7f, -0.6f, 0.0f, //4
		0.0f, -0.3f, 0.0f, //5
		-0.6f, -0.6f, 0.0f,
		-0.6f, 0.0f, 0.0f,
		-0.7, 0.4f, 0.0f,
		-0.4f, 0.4f, 0.0f
	};

	GLuint indices[] = {
		0,1,9,
		1,2,3,
		3,4,5,
		5,6,7,
		7,8,9,
		1,3,5,
		5,7,9,
		1,9,5
	};

	glfwMakeContextCurrent(window); // introduce the window to the current context

	gladLoadGL(); // load GLAD so it can configue OpenGL

	glViewport(0, 0, 800, 800); // In here it goes from x:0, y:0 to x:800, y:800

	Shader shaderProgram("default.vert", "default.frag");

	VAO VAO1;
	VAO1.Bind();

	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));

	VAO1.LinkVBO(VBO1, 0);
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	

	while (!glfwWindowShouldClose(window)) {

		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		shaderProgram.Activate();
		VAO1.Bind();
		glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();
	

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;

}