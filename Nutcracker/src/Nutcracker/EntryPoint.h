#pragma once

#ifdef NC_PLATFORM_WINDOWS

extern Nutcracker::Application* Nutcracker::CreateApplication();

int main(int arg, char** argv) {
	auto app = Nutcracker::CreateApplication();
	app->Run();
	delete app;
}

#endif