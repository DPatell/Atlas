#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Atlas
{
	class ATLAS_API Application
	{
	public:
		Application();
		~Application();

		void Run();
	};

	// To be defined in the client
	Application* CreateApplication();
}