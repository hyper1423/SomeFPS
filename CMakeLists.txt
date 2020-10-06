cmake_minimum_required(VERSION 2.81)

project("SomeFPS")
set(SOMEFPS_OUTPUT "someFPS")
set(SOMEFPS_SRC_FILES 
"Main.cpp"
    "callbacks/ErrorCallback.cpp"
    "exceptions/resources/ResourceNotFoundException.cpp"
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
            "renderer/resources/texture/image/Image.cpp"
    "resources/ResourceLoader.cpp"
    "resources/Resource.cpp"
        "resources/factories/TextLoader.cpp"
        "resources/factories/ModelLoader.cpp"
        "resources/factories/ImageLoader.cpp"
    "window/Window.cpp"
#Triangle.cpp"
)
#set(SRC_FILES Main.cpp)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

find_package(assimp REQUIRED)
find_package(OpenGL 4.5 REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)
find_package(Freetype REQUIRED)
find_package(OpenCV COMPONENTS imgcodecs imgproc videoio REQUIRED)

add_executable(${SOMEFPS_OUTPUT} ${SOMEFPS_SRC_FILES})

target_include_directories(${SOMEFPS_OUTPUT} PRIVATE ${ASSIMP_INCLUDE_DIRS})
target_include_directories(${SOMEFPS_OUTPUT} PRIVATE ${OPENGL_INCLUDE_DIRS})
target_include_directories(${SOMEFPS_OUTPUT} PRIVATE ${GLFW3_INCLUDE_DIRS})
target_include_directories(${SOMEFPS_OUTPUT} PRIVATE ${GLEW_INCLUDE_DIRS})
target_include_directories(${SOMEFPS_OUTPUT} PRIVATE ${glm_INCLUDE_DIRS})
target_include_directories(${SOMEFPS_OUTPUT} PRIVATE ${Freetype_INCLUDE_DIRS})
target_include_directories(${SOMEFPS_OUTPUT} PRIVATE ${OpenCV_INCLUDE_DIRS})

target_link_directories(${SOMEFPS_OUTPUT} PRIVATE ${ASSIMP_LIBRARY_DIRS})
target_link_directories(${SOMEFPS_OUTPUT} PRIVATE ${OPENGL_LIBRARY_DIRS})
target_link_directories(${SOMEFPS_OUTPUT} PRIVATE ${GLFW3_LIBRARY_DIRS})
target_link_directories(${SOMEFPS_OUTPUT} PRIVATE ${GLEW_LIBRARY_DIRS})
target_link_directories(${SOMEFPS_OUTPUT} PRIVATE ${FREETYPE_LIBRARY_DIRS})
target_link_directories(${SOMEFPS_OUTPUT} PRIVATE ${OpenCV_LIBRARY_DIRS})

target_link_libraries(${SOMEFPS_OUTPUT} PRIVATE assimp::assimp)
target_link_libraries(${SOMEFPS_OUTPUT} PRIVATE ${OPENGL_gl_LIBRARY})
target_link_libraries(${SOMEFPS_OUTPUT} PRIVATE glfw)
target_link_libraries(${SOMEFPS_OUTPUT} PRIVATE GLEW::GLEW)
target_link_libraries(${SOMEFPS_OUTPUT} PRIVATE Freetype::Freetype)
target_link_libraries(${SOMEFPS_OUTPUT} PRIVATE ${OpenCV_LIBRARIES})
#target_compile_options(${SOMEFPS_OUTPUT} PRIVATE "/P")

add_compile_definitions(OPENCV_TRAITS_ENABLE_DEPRECATED)

set_target_properties(${SOMEFPS_OUTPUT} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)