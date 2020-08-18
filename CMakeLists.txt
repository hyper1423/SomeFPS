CMAKE_MINIMUM_REQUIRED ( VERSION 2.81 )

SET ( SRC_FILES 
Main.cpp 
    "callbacks/ErrorCallback.cpp"
    "game/Game.cpp" 
    "game/GLFWManager.cpp"
        "game/game_objects/GameObject.cpp"
        "game/game_objects/3D/CubeObject.cpp"
        "game/ticking/GameTicker.cpp"
    "logger/Logger.cpp"
    "renderer/Renderer.cpp"
        "renderer/model/Mesh.cpp"
        "renderer/model/Model.cpp"
        "renderer/transformation/Transformation.cpp"
        "renderer/vertex_array/VertexArray.cpp"
            "renderer/resources/shader/ShaderProgram.cpp"
            "renderer/resources/material/Material.cpp"
    "resources/ResourceLoader.cpp"
    "resources/ResourceImpl.cpp"
        "resources/factories/TextLoader.cpp"
        "resources/factories/ModelLoader.cpp"
    "window/Window.cpp"
#Triangle.cpp"
)
#SET ( SRC_FILES Main.cpp )
SET ( CMAKE_CXX_STANDARD 17 )
SET ( CMAKE_CXX_STANDARD_REQUIRED ON )
SET ( CMAKE_BUILD_TYPE Debug )

PROJECT ( ALL_BUILD )
ADD_COMPILE_OPTIONS ( /Ob0 )

LINK_DIRECTORIES ( ${PROJECT_SOURCE_DIR}/lib )
INCLUDE_DIRECTORIES ( ${PROJECT_SOURCE_DIR}/include )

ADD_EXECUTABLE ( someFPS ${SRC_FILES} )

TARGET_LINK_LIBRARIES ( someFPS assimp-vc142-mt )
TARGET_LINK_LIBRARIES ( someFPS opengl32 )
TARGET_LINK_LIBRARIES ( someFPS glfw3dll )
TARGET_LINK_LIBRARIES ( someFPS glew32 )
TARGET_LINK_LIBRARIES ( someFPS libpng16d )
TARGET_LINK_LIBRARIES ( someFPS freetyped )

SET_TARGET_PROPERTIES ( someFPS PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin )