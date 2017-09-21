#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <string>
#include "ErrorHandler.hpp"

class Texture
{
public:
	Texture(const std::string& file);
	virtual ~Texture() {};

	void bindTexture(unsigned int slot = GL_TEXTURE0);

	bool operator==(const std::string& other) {
		return this->file == other;
	}
private:
	std::string file;
	unsigned int texture_id;
	int width, height, nrChannels;
};

#endif