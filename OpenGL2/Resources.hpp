#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include <vector>
#include <string>
#include "Shader.hpp"
#include "Texture.hpp"

class Resources
{
public:
	Resources();
	virtual ~Resources();

	void addShader(Shader& shader)
	{

		this->shaders.push_back(shader);
	}
	void addTexture(Texture& texture)
	{
		this->textures.push_back(texture);
	}

private:
	std::vector<Shader> shaders;
	std::vector<Texture> textures;
};

#endif