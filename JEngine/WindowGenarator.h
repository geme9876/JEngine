#pragma once
#include "pch.h"
#include "JException.h"
#include "WinGenMacro.h"
#include "Keyboard.h"
#include "Mouse.h"
#include <optional>
#include <memory>


class WindowGenarator
{
public:
	class WinGenException : public JException
	{
		using JException::JException;
	public:
		static std::string TranslateErrorCode(HRESULT hr) noexcept;
	};
	class HRException : public WinGenException
	{
	public:
		HRException(int line, const char* file, HRESULT hr) noexcept;
		const char* what() const noexcept override;
		const char* GetType() const noexcept override;
		HRESULT GetErrorCode() const noexcept;
		std::string GetErrorDescription() const noexcept;
	private:
		HRESULT hr;
	};
	class NoGfxException : public WinGenException
	{
	public:
		using WinGenException::WinGenException;
		const char* GetType() const noexcept override;
	};
private:
	class WindowClass
	{
	public:
		static const TCHAR* GetName() noexcept;
		static HINSTANCE GetInstance() noexcept;
	private:
		WindowClass() noexcept;
		~WindowClass();
		WindowClass(const WindowClass&) = delete;
		WindowClass& operator= (const WindowClass&) = delete;


		static constexpr const TCHAR* wndClassName = _T("This will be WindowClassName");
		static WindowClass wndClass;
		HINSTANCE hInst;
	};
public:
	WindowGenarator(int W, int H, const TCHAR* name);
	~WindowGenarator();
	WindowGenarator(const WindowGenarator&) = delete;
	WindowGenarator& operator=(const WindowGenarator&) = delete;
	void SetTitle(const tstring& title);
	void EnableCursor() noexcept;
	void DisableCursor() noexcept;
	bool IsCursorEnable() const noexcept;
	static std::optional<int> ProcessMessages() noexcept;

	Keyboard& GetKeyboard() noexcept { return kbd; }
	Mouse& GetMouse()  noexcept { return mouse; }

private:
	void ConfineCursor() noexcept;
	void FreeCursor() noexcept;
	void ShowCursor() noexcept;
	void HideCursor() noexcept;
	static LRESULT CALLBACK HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	static LRESULT CALLBACK HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	LRESULT HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;


private:
	Keyboard kbd;
	Mouse mouse;
private:
	bool cursorEnabled = true;
	int width;
	int height;
	HWND hWnd;
	std::vector<BYTE> rawBuffer;
};


