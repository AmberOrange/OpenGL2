#include "Texture.hpp"

Texture::Texture(const std::string& file)
{
	this->file = file;
	unsigned char* colour_raw;

	colour_raw = stbi_load(file.c_str(), &this->width, &this->height, &this->nrChannels, 0);
	if (colour_raw == NULL)
		throw StreamableError() << "Couldn't open file " << file;

	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->width, this->height, 0, GL_RGB, GL_UNSIGNED_BYTE, colour_raw);
	glGenerateMipmap(GL_TEXTURE_2D);		// DO I NEED THIS?

	stbi_image_free(colour_raw);
}

void Texture::bindTexture(unsigned int slot)
{
	glActiveTexture(slot);
	glBindTexture(GL_TEXTURE_2D, this->texture_id);
}
