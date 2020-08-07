CMAKE_MINIMUM_REQUIRED ( VERSION 2.81 )

SET ( SRC_FILES 
Main.cpp 
    callbacks/ErrorCallback.cpp 
    game/Game.cpp 
    game/GLFWManager.cpp 
        game/game_objects/GameObject.cpp
        game/ticking/GameTicker.cpp 
    logger/Logger.cpp 
    renderer/Renderer.cpp 
        renderer/model/Mesh.cpp 
        renderer/model/Model.cpp 
        renderer/transformation/Transform.cpp 
        renderer/vertex_array/VertexArray.cpp 
            renderer/resources/shader/ShaderProgram.cpp 
    resources/ResourceLoader.cpp 
    resources/ResourceImpl.cpp 
        resources/factories/TextLoader.cpp 
        resources/factories/OBJLoader.cpp 
    window/Window.cpp 
#Triangle.cpp 
)
#SET ( SRC_FILES Main.cpp )
SET ( CMAKE_CXX_STANDARD 17 )
SET ( CMAKE_CXX_STANDARD_REQUIRED ON )
SET ( CMAKE_BUILD_TYPE Debug )

PROJECT ( ALL_BUILD )
ADD_COMPILE_OPTIONS ( -g -Wall -pedantic-errors )
ADD_COMPILE_OPTIONS ( -lassimp-vc142-mt )

INCLUDE_DIRECTORIES ( ${PROJECT_SOURCE_DIR}/include )

ADD_EXECUTABLE ( someFPS ${SRC_FILES} )

TARGET_LINK_LIBRARIES ( someFPS ${PROJECT_SOURCE_DIR}/lib/assimp-vc142-mt )
TARGET_LINK_LIBRARIES ( someFPS ${PROJECT_SOURCE_DIR}/lib/opengl32 )
TARGET_LINK_LIBRARIES ( someFPS ${PROJECT_SOURCE_DIR}/lib/glfw3dll )
TARGET_LINK_LIBRARIES ( someFPS ${PROJECT_SOURCE_DIR}/lib/glew32 )
TARGET_LINK_LIBRARIES ( someFPS ${PROJECT_SOURCE_DIR}/lib/libpng16d )
TARGET_LINK_LIBRARIES ( someFPS ${PROJECT_SOURCE_DIR}/lib/freetyped )

SET_TARGET_PROPERTIES ( someFPS PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin )