#include "atlpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <Glad/glad.h>
#include <GL/GL.h>

namespace Atlas
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) : m_WindowHandle(windowHandle)
	{
		ATL_CORE_ASSERT(windowHandle, "Window Handle is Null!!!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ATL_CORE_ASSERT(status, "Failed to initialize Glad!");

		ATL_CORE_INFO("OpenGL Info: ");
		ATL_CORE_INFO("	Vendor:   {0}", glGetString(GL_VENDOR));
		ATL_CORE_INFO("	Renderer: {0}", glGetString(GL_RENDERER));
		ATL_CORE_INFO("	Version:  {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}