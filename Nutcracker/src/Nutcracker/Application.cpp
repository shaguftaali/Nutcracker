#include "ncpch.h"
#include "Application.h"
//#include "Event/ApplicationEvent.h"
//#include "Event/MouseEvent.h"
//#include "Event/KeyEvent.h"
#include"Nutcracker/Log.h"

namespace Nutcracker {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WnidowResizeEvent e(1280, 720);
		////WindowCloseEvent e;
		if (e.IsInCategory(EventCategoryApplication)) {
			NC_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput)) {
			NC_TRACE(e);
		}
		while (m_Running) {
			m_Window->OnUpdate();
		}
	}
	void Application::OnEvent(Event& e)
	{
		EventDispature dispature(e);
		dispature.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		NC_CORE_INFO("{0}", e);
	}
	bool Application::OnWindowClose(WindowCloseEvent & e)
	{
		m_Running = false;
		return true;
	}
}


