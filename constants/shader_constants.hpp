#ifndef SHADER_CONSTANTS_HPP
#define SHADER_CONSTANTS_HPP

#include <GL/glew.h>

namespace constants {
    enum class ShaderTypes { 
	    VERTEX_SHADER = GL_VERTEX_SHADER,
        FRAGMENT_SHADER = GL_FRAGMENT_SHADER
    };
}

#endif