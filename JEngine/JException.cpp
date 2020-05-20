#include "pch.h"
#include "JException.h"
#include <sstream>
JException::JException(int line, const char* file) noexcept:line(line),file(file)
{
}

const char* JException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* JException::GetType() const noexcept
{
	return "JException";
}

int JException::GetLine() const noexcept
{
	return line;
}

const std::string& JException::GetFile() const noexcept
{
	return file;
}

std::string JException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}
