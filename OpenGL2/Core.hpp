#ifndef CORE_HPP
#define CORE_HPP

#include <GLFW\glfw3.h>

#include "Time.hpp"
#include "Input.hpp"

class Core
{
public:
	Core(GLFWwindow* window);
	virtual ~Core();

	void processInput(GLFWwindow* window);
	void update(GLFWwindow* window, const Time& time);
	void render(GLFWwindow* window, const Time& time);

private:
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	Input input;
};

#endif