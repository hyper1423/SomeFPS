CMAKE_MINIMUM_REQUIRED ( VERSION 2.81 )

SET ( SRC_FILES 
Main.cpp Shader.cpp Logger.cpp ErrorHandler.cpp StateManager.cpp VertexArray.cpp 
Window.cpp IRenderable.cpp Renderer.cpp )
SET ( CMAKE_CXX_STANDARD 17 )
SET ( CMAKE_CXX_STANDARD_REQUIRED ON )
SET ( CMAKE_BUILD_TYPE Debug )

ADD_COMPILE_OPTIONS ( -g )
LINK_DIRECTORIES ( ${CMAKE_CURRENT_SOURCE_DIR}/lib )
PROJECT ( ALL_BUILD )

ADD_EXECUTABLE ( someFPS ${SRC_FILES} )
TARGET_LINK_LIBRARIES ( someFPS opengl32 glfw3dll glew32 )