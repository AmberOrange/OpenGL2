#ifndef SHADER_HPP
#define SHADER_HPP
#define char_uc const unsigned char

#include <glad\glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
	struct vertexShaders
	{
		enum : char_uc {
			passthrough
		};
	};
	struct geometryShaders
	{
		enum : char_uc {
			noShader,
			passthrough
		};
	};
	struct fragmentShaders
	{
		enum : char_uc {
			passthrough
		};
	};
private:
	const char* vertexPath[1] =
	{
		"fes"
	};

public:
	unsigned int ID;

	Shader(char_uc vertexID, char_uc fragmentID, char_uc geometryID = geometryShaders::noShader);

	void compile();

	void use();

	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;

	bool operator==(const Shader& other);
private:
	char_uc vertexID, geometryID, fragmentID;
};

#endif