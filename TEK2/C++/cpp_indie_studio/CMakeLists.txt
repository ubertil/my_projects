cmake_minimum_required(VERSION 3.4)
project(cpp_indie_studio)
set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES srcs/main.cpp include/Utils/Dir.hpp include/Utils/Random.hpp include/Game/Car.hh srcs/Game/Car.cpp include/Sound/Manager.hh srcs/Sound/Manager.cpp include/Sound/Source.hh srcs/Sound/Source.cpp include/GUI/Menu.hh include/Game/Circuit.hh srcs/GUI/Menu.cpp include/Game/Core.hpp srcs/Game/Core.cpp srcs/RessourceLoader.cpp srcs/Game/Circuit.cpp include/Language.hpp include/Game/Model.hh include/Input/Event.hh include/Input/Controller.hh srcs/Input/Controller.cpp srcs/Input/Event.cpp include/GUI/OptionsMenu.hh include/GUI/IMenuItem.hh include/GUI/MainMenu.hh srcs/GUI/MainMenu.cpp srcs/GUI/OptionsMenu.cpp include/GUI/CreditsMenu.hh srcs/GUI/CreditsMenu.cpp include/GUI/QuitMenu.hh include/GUI/CarMenu.hh srcs/GUI/CarMenu.cpp srcs/GUI/QuitMenu.cpp srcs/Physic/Physic.cpp srcs/Font/CGUITTFont.cpp srcs/Font/CStringTable.cpp include/Font/irrUString.hpp include/Font/CGUITTFont.hpp include/Font/CStringTable.hpp srcs/Utils/IniManager.cpp include/Utils/IniManager.hpp include/Game/Camera.hh include/GUI/ATH.hh srcs/GUI/ATH.cpp include/GUI/PauseMenu.hh srcs/GUI/PauseMenu.cpp include/Game/BasicModel.hpp)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/include/freetype)
add_executable(hyper_sprint ${SOURCE_FILES})

if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	set(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra -O3 -lpthread -lGL -lX11 -lXxf86vm")
	target_link_libraries(hyper_sprint ${CMAKE_SOURCE_DIR}/lib/Linux/libIrrlicht.a ${CMAKE_SOURCE_DIR}/lib/Linux/libopenal/libopenal.so.1
			${CMAKE_SOURCE_DIR}/lib/Linux/libsndfile/libsndfile.so ${CMAKE_SOURCE_DIR}/lib/Linux/libfreetype.a ${CMAKE_SOURCE_DIR}/lib/Linux/libharfbuzz.so)

endif()
