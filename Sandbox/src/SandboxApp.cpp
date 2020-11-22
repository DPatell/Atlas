#include <Atlas.h>

#include "imgui/imgui.h"

class ExampleLayer : public Atlas::Layer
{
public:
	ExampleLayer() : Layer("Example")
	{

	}

	void OnUpdate() override
	{
			if (Atlas::Input::IsKeyPressed(ATL_KEY_TAB))
				ATL_TRACE("Tab Key Is Pressed (Poll)!");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("HelloWorld");
		ImGui::End();
	}

	void OnEvent(Atlas::Event& event) override
	{
		if (event.GetEventType() == Atlas::EventType::KeyPressed)
		{
			Atlas::KeyPressedEvent& e = (Atlas::KeyPressedEvent&)event;
			if (e.GetKeyCode() == ATL_KEY_TAB)
				ATL_TRACE("Tab Key Is Pressed (Event)!");
			ATL_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public Atlas::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Atlas::Application* Atlas::CreateApplication()
{
	return new Sandbox();
}