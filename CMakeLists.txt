cmake_minimum_required(VERSION 3.0)

set(src src/main.cpp)


if(EMSCRIPTEN)
	
	set(flags "-std=c++11 -s USE_GLFW=3 -s FULL_ES2=1 -s FORCE_FILESYSTEM=1")

	set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} ${flags})
	set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${flags})

	add_executable (opengl_example ${src})

elseif (ANDROID)
   
	add_library(opengl_example SHARED ${src})

	target_link_libraries(opengl_example
		android
        	log
        	GLESv2
        	EGL
    	)

else()

	if(WINDOWS)
		if(WINDOWS EQUAL 32)
		set(CMAKE_PREFIX_PATH /usr/i686-w64-mingw32)
		elseif(WINDOWS EQUAL 64)
		set(CMAKE_PREFIX_PATH /usr/x86_64-w64-mingw32)
		endif()
	endif()

	find_package(wxWidgets COMPONENTS core base gl net REQUIRED)
	find_package(OpenGL REQUIRED)
	find_package(GLUT REQUIRED)

	link_directories(${GLUT_LIBRARY_DIRS})
	include_directories(${GLUT_INCLUDE_DIRS})


	include(${wxWidgets_USE_FILE})

	add_executable (opengl_example ${src})

	target_link_libraries(opengl_example
		       ${wxWidgets_LIBRARIES}
		      ${GLUT_LIBRARIES}
			${OPENGL_LIBRARIES})

endif()
