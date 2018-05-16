cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(SmartVFR)

find_package(PCL 1.2 REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui)

set(CMAKE_INCLUDE_CURRENT_DIR ON)


set(project_ui 
    mainwindow.ui)

set(project_headers 
    mainwindow.h)

set(project_sources 
    SmartVFR.cpp
    mainwindow.cpp)

qt5_wrap_ui(project_headers_wrapped ${project_ui})
qt5_wrap_cpp(project_sources_moc ${project_headers})

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(${PROJECT_NAME} ${project_headers} ${project_sources} 
    ${project_sources_moc} ${project_headers_wrapped})

target_link_libraries(${PROJECT_NAME}
    PUBLIC 
	${PCL_LIBRARIES} 
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets)