#include "Application.h"

#include "Atlas/Log.h"
#include "Atlas/Events/ApplicationEvent.h"

namespace Atlas
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			ATL_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			ATL_TRACE(e);
		}

		while (true);
	}
}