#include "pch.h"
#include "JTimer.h"


JTimer::JTimer() noexcept
{
	last = std::chrono::steady_clock::now();
}

float JTimer::Mark() noexcept
{
	const auto old = last;
	last = std::chrono::steady_clock::now();
	const std::chrono::duration<float> frameTime = last - old;
	return frameTime.count();
}

float JTimer::Peek() const noexcept
{
	return std::chrono::duration<float>(std::chrono::steady_clock::now() - last).count();
}
