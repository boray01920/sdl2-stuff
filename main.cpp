#include "Mesh.h"
#include "MeshData.h"

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

	glfwMakeContextCurrent(window); // introduce the window to the current context

	gladLoadGL(); // load GLAD so it can configue OpenGL

	glViewport(0, 0, width, height); // In here it goes from x:0, y:0 to x:800, y:800

	// texturing

	Texture textures[] = {
		Texture("neuro.png", "diffuse", GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("evil.png", "diffuse", GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("grass.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("grassSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};

	Shader shaderProgram("default.vert", "default.frag");
	Shader lightShader("light.vert", "light.frag");

	std::vector<Vertex> cubeVerts(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
	std::vector<GLuint> cubeInd(indices, indices + sizeof(indices) / sizeof(GLuint));
	std::vector<Texture> cubeTex = {
		Texture("neuro.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE)
	};
	Mesh cube(cubeVerts, cubeInd, cubeTex);
	cube.model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));

	// Light cube
	std::vector<Vertex> lightVerts(lightVertices, lightVertices + sizeof(lightVertices) / sizeof(Vertex));
	std::vector<GLuint> lightInd(lightIndices, lightIndices + sizeof(lightIndices) / sizeof(GLuint));
	std::vector<Texture> lightTex = {
		Texture("evil.png", "diffuse", 1, GL_RGBA, GL_UNSIGNED_BYTE)
	};
	Mesh light(lightVerts, lightInd, lightTex);

	glm::vec3 lightPos = glm::vec3(1.0f, 0.5f, 1.0f); // near the cube, offset so it's clearly visible
	light.model = glm::translate(glm::mat4(1.0f), lightPos);

	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

	lightShader.Activate();
	glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	shaderProgram.Activate();
	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);







	glEnable(GL_DEPTH_TEST);

	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));


	while (!glfwWindowShouldClose(window)) {

		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		camera.Inputs(window);
		camera.updateMatrix(45.0f, 0.1f, 100.0f);

		light.Draw(lightShader, camera);
		cube.Draw(shaderProgram, camera);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	shaderProgram.Delete();


	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;

}