#pragma once

#ifdef ATL_PLATFORM_WINDOWS

extern Atlas::Application* Atlas::CreateApplication();

int main(int argc, char** argv)
{
	Atlas::Log::Init();
	ATL_CORE_WARN("Initialized Log!");
	int a = 5;
	ATL_INFO("SUP! Var={0}", a);

	auto app = Atlas::CreateApplication();
	app->Run();
	delete app;
}

#endif