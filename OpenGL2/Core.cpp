#include "Core.hpp"

Core::Core(GLFWwindow* window)
{
	glViewport(0, 0, 800, 600);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

Core::~Core()
{
}

void Core::processInput(GLFWwindow* window)
{
	this->input.update(window);
}

void Core::update(GLFWwindow* window, const Time& time)
{
	if (this->input.keyDown(Input::SELECT))
		glfwSetWindowShouldClose(window, true);

}

void Core::render(GLFWwindow* window, const Time& time)
{
	glClearColor(0.0f, 0.3f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwSwapBuffers(window);
}

void Core::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
