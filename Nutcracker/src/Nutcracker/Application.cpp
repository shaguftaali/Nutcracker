#include "Application.h"
#include "Event/ApplicationEvent.h"
#include"Nutcracker/Log.h"

namespace Nutcracker {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WnidowResizeEvent e(1280, 720);
		//WindowCloseEvent e;
		if (e.IsInCategory(EventCategoryApplication)) {
			//NC_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput)) {
			//HZ_TRACE(e);
		}
		while (true) {

		}
	}
}


