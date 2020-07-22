CMAKE_MINIMUM_REQUIRED ( VERSION 2.81 )

SET ( SRC_FILES 
    Main.cpp ErrorHandler.cpp Game.cpp GameTick.cpp GLFWManager.cpp Logger.cpp 
    Renderer.cpp ResourceLoader.cpp resources_impl.cpp Shader.cpp Transform.cpp 
    VertexArray.cpp Window.cpp)
#SET ( SRC_FILES Main.cpp )
SET ( CMAKE_CXX_STANDARD 17 )
SET ( CMAKE_CXX_STANDARD_REQUIRED ON )
SET ( CMAKE_BUILD_TYPE Debug )

PROJECT ( ALL_BUILD )
ADD_COMPILE_OPTIONS ( -g -Wall -pedantic-errors )
LINK_DIRECTORIES ( ${PROJECT_SOURCE_DIR}/lib )
INCLUDE_DIRECTORIES ( ${PROJECT_SOURCE_DIR}/include )

ADD_EXECUTABLE ( someFPS ${SRC_FILES} )
SET_TARGET_PROPERTIES ( someFPS PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin )
TARGET_LINK_LIBRARIES ( someFPS opengl32 glfw3dll glew32 libpng16d freetyped )