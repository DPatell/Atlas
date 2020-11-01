#pragma once

#include "Core.h"

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