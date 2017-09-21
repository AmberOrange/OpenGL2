#ifndef TIME_HPP
#define TIME_HPP

#include <GLFW\glfw3.h>

class Time
{
public:
	Time() {
		this->elapsedTime = 
		this->previousTime = 
		this->deltaTime = 0;
	};
	virtual ~Time() {};

	void update(const double elapsedTime) {
		this->previousTime = this->elapsedTime;
		this->elapsedTime = elapsedTime;
		this->deltaTime = this->elapsedTime - this->previousTime;
	}

	float getElapsedTime() const {
		return (float)this->elapsedTime;
	}
	float getTime() const {
		return (float)this->deltaTime;
	}

	double getDoubleElapsedTime() const {
		return this->elapsedTime;
	}
	double getDoubleTime() const {
		return this->deltaTime;
	}

private:
	double elapsedTime;
	double previousTime;
	double deltaTime;
};

#endif 