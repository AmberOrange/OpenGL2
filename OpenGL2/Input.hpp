#ifndef INPUT_HPP
#define INPUT_HPP
#define TOTAL_BUTTONS 8

#include <GLFW\glfw3.h>

class Input
{
public: 
	const enum button : unsigned char {
		A = 0x01,
		B = 0x02,
		START = 0x04,
		SELECT = 0x08,
		UP = 0x10,
		DOWN = 0x20,
		LEFT = 0x40,
		RIGHT = 0x80
	};
private:
	const int predefined_keys[TOTAL_BUTTONS] = {
		GLFW_KEY_Z,
		GLFW_KEY_X,
		GLFW_KEY_SPACE,
		GLFW_KEY_ESCAPE,
		GLFW_KEY_UP,
		GLFW_KEY_DOWN,
		GLFW_KEY_LEFT,
		GLFW_KEY_RIGHT
	};
	const unsigned char button_map[TOTAL_BUTTONS]{ A, B, START, SELECT, UP, DOWN, LEFT, RIGHT };
public:
	Input() {
		this->current_press = 0x0;
		this->previous_press = 0x0;
	};
	virtual ~Input() {};

	void update(GLFWwindow* window)
	{
		previous_press = current_press;
		current_press = 0x0;
		for (int i = 0; i < TOTAL_BUTTONS; i++)
		{
			current_press |= (glfwGetKey(window, this->predefined_keys[i]) == GLFW_PRESS) ? button_map[i] : 0x0;
		}
	}

	bool keyDown(const button key) const
	{
		return (current_press & key) == key;
	}
	bool keyPress(const button key) const
	{
		return ((current_press & key) & previous_press) == 0x0;
	}

private:
	unsigned char current_press;
	unsigned char previous_press;
	
};

#endif