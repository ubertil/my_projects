cmake_minimum_required(VERSION 3.6)
project(plazza)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	set(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra -Werror -O3")
	find_package(threads)
else()
	set(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra -Werror -O3 -lpthread")
endif()
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(SOURCE_FILES srcs/main.cpp srcs/Core.cpp srcs/Process/ProcessManager.cpp include/Process/ProcessManager.hh include/Core.hh include/Information.hh srcs/Process/Process.cpp include/Process/Process.hh include/Thread/Pool.hh srcs/Thread/Pool.cpp include/Process/Fork.hh include/Process/IForkable.hh srcs/Process/Fork.cpp include/Thread/CondVar.hpp include/Network/Server.hpp srcs/Network/Server.cpp include/Network/Client.hpp srcs/Network/Client.cpp include/Error.hpp include/SafeQueue.hpp srcs/UI/UI.cpp include/UI/UI.hh)
include_directories(include)

add_executable(plazza ${SOURCE_FILES})
