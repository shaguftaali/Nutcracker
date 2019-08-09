#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include <memory.h>

namespace Nutcracker {

	class NUTCRACKER_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {
			return s_CoreLogger;
		}

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { 
			return s_ClientLogger; 
		}


	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define NC_CORE_TRACE(...)		::Nutcracker::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NC_CORE_INFO(...)		::Nutcracker::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NC_CORE_WARN(...)		::Nutcracker::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NC_CORE_ERROR(...)		::Nutcracker::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NC_CORE_FATAL(...)		::Nutcracker::Log::GetCoreLogger()->fatal(__VA_ARGS__)


//Client log macros
#define NC_CLIENT_TRACE(...)		::Nutcracker::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NC_CLIENT_INFO(...)			::Nutcracker::Log::GetClientLogger()->info(__VA_ARGS__)
#define NC_CLIENT_WARN(...)			::Nutcracker::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NC_CLIENT_ERROR(...)		::Nutcracker::Log::GetClientLogger()->error(__VA_ARGS__)
#define NC_CLIENT_FATAL(...)		::Nutcracker::Log::GetClientLogger()->fatal(__VA_ARGS__)

//if dist built
#define NC_CORE_INFO
