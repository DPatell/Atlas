#pragma once

#include "atlpch.h"

#include "Atlas/Core.h"
#include "Atlas/Events/Event.h"

namespace Atlas
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Atlas Engine", unsigned int width = 1280, unsigned int height = 720) : Title(title), Width(width), Height(height)
		{

		}
	};

	// This is an interface that represents an OS specific Window
	class ATLAS_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;
		
		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window Attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}