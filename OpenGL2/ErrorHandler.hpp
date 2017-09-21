#ifndef ERRORHANDLER_HPP
#define ERRORHANDLER_HPP

#include <sstream>

struct StreamableError : public std::exception {
	template <typename T>
	StreamableError& operator << (T rhs) {
		innerStream << rhs;
		return *this;
	}

	StreamableError() = default;

	StreamableError(StreamableError& rhs) {
		innerStream << rhs.innerStream.str();
	}

	virtual const char* what() const noexcept {
		str = innerStream.str();  //this can throw
		return str.c_str();
	}

private:
	std::stringstream innerStream;
	mutable std::string str;
};

#endif