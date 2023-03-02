cmake_minimum_required(VERSION 3.14)
project(VGL C CXX)
set(CMAKE_CXX_STANDARD 14)

# add_subdirectory(lib/glfw)
add_subdirectory(lib/FFmpeg)

add_definitions(-DGL_SILENCE_DEPRECATION)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/libs)
include_directories(${PROJECT_SOURCE_DIR})
file(COPY Assets DESTINATION ${CMAKE_BINARY_DIR})


add_executable(Random 
    Random/run.cpp
    VGL/Scenes.hpp
    VGL/common.hpp
    src/Switcher.cpp
    src/video_reader.cpp
    VGL/video_reader.hpp
    src/load_texture.cpp
    src/Scene1/scene1.cpp
    src/Scene2/scene2.cpp
    )

if(APPLE)
    list(APPEND EXTRA_LIBS
        "-framework OpenGL"
    )

    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/assets/MacOSXBundleInfo.plist.in
        ${CMAKE_CURRENT_BINARY_DIR}/assets/MacOSXBundleInfo.plist
    )

    set_target_properties(video-app PROPERTIES
        MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_BINARY_DIR}/assets/MacOSXBundleInfo.plist
    )

elseif(WIN32)
    list(APPEND EXTRA_LIBS
        "-lglu32 -lopengl32"
    )
    set(CMAKE_EXE_LINKER_FLAGS "-std=gnu99 -static -static-libgcc -static-libstdc++ -mwindows")
else()
    list(APPEND EXTRA_LIBS
        "-lGL -lGLU -lGLEW -lglfw -lSOIL"
    )
endif()

target_link_libraries(Random FFmpeg ${EXTRA_LIBS})
