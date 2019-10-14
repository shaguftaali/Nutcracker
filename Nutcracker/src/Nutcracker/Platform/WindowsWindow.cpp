#include "ncpch.h"
#include "WindowsWindow.h"
//#include "../Event/ApplicationEvent.h"
#include "../Event/ApplicationEvent.h"
#include "../Event/MouseEvent.h"
#include "../Event/KeyEvent.h"
#include "../Log.h"

namespace Nutcracker {

	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description) {
		//NC_CORE_ERROR("GLFW Error ({0}) : {1}", error, description);
	}

	Window* Nutcracker::Window::Create(const WindowProps& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps & props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
	}

	void WindowsWindow::OnUpdate() const
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled) {
			glfwSwapInterval(1);
		}
		else {
			glfwSwapInterval(0);
		}
		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

	void WindowsWindow::Init(const WindowProps & props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		NC_CORE_INFO("Createing window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			//NC_CORE_ASSERT(success, "Could not initialize GLFW");
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(),nullptr,nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);


		//Set GLFW callback
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowData* dataPtr = (WindowData*)glfwGetWindowUserPointer(window);
			WindowData& data = *dataPtr;
			data.Width = width;
			data.Height = height;

			WnidowResizeEvent event(width, height);
			data.EventCallback(event);
			
		});


		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			WindowData* dataPtr = (WindowData*)glfwGetWindowUserPointer(window);
			WindowData& data = *dataPtr;
			WindowCloseEvent event;
			data.EventCallback(event);
		});


		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scanCode, int action, int mods)
		{
			WindowData* dataPtr = (WindowData*)glfwGetWindowUserPointer(window);
			WindowData& data = *dataPtr;
		
			switch (action) {

			case GLFW_PRESS:
			{
				KeyPressedEvent event(key, 0);
				data.EventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				KeyReleasedEvent event(key);
				data.EventCallback(event);
				break;
			}
			case GLFW_REPEAT:
			{
				KeyPressedEvent event(key, 1);
				data.EventCallback(event);
				break;
			}
			}
				
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
			case GLFW_PRESS:
			{
				MouseButtonReleasedEvent event(button);
				data.EventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				MouseButtonReleasedEvent event(button);
				data.EventCallback(event);
				break;
			}
			default:
				break;
			}
		});
	
		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.EventCallback(event);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMoveEvent event((float)xPos, (float)yPos);
			data.EventCallback(event);
		});

	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

}
