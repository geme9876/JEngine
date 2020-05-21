#pragma once
#include "WindowGenarator.h"
#include "JTimer.h"
class JCore
{
public:
	JCore(int W,int H,const TCHAR* wndName, const std::string& commandLine = "");
	~JCore();

private:
	int RunCore();
	void Frame(float delta);
	void HandleInput(float delta);

private:
	std::string commandLine;
	WindowGenarator wnd;
	JTimer timer;
	float speed_factor = 1.0f;
};

