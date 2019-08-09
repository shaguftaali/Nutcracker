#pragma once
#ifdef NC_PLATFORM_WINDOWS

extern Nutcracker::Application* Nutcracker::CreateApplication();

int main(int arg, char** argv) {
	
	Nutcracker::Log::Init();
	Nutcracker::Log::GetCoreLogger()->warn("Initialized Log");
	Nutcracker::Log::GetClientLogger()->info("Client info");
	//NC_CORE_WARN("WARNING");
	NC_CORE_ERROR("ERROR");
	auto app = Nutcracker::CreateApplication();
	app->Run();
	delete app;
}

#endif