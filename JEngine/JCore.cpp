#include "pch.h"
#include "JCore.h"

JCore::JCore(int W,int H, const TCHAR* wndName,const std::string& commandLine) : commandLine(commandLine),wnd(W,H, wndName)
{
}

JCore::~JCore()
{
}

int JCore::RunCore()
{
	while (true)
	{
		// process all messages pending, but to not block for new messages
		if (const auto ecode = WindowGenarator::ProcessMessages())
		{
			// if return optional has value, means we're quitting so return exit code
			return *ecode;
		}
		// execute the game logic
		const auto dt = timer.Mark() * speed_factor;
		HandleInput(dt);
		Frame(dt);
	}
}

void JCore::Frame(float delta)
{
}

void JCore::HandleInput(float delta)
{
	while (const auto e = wnd.GetKeyboard().ReadKey())
	{
		if (!e->IsPress())
		{
			continue;
		}
	}
}
