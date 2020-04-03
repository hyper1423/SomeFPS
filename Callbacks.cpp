#include "someFPS.hpp"
#include <iostream>

namespace callbacks {
    void ErrorCallback(int errCode, const char* errDesc) {
        Logger::getInstance().log(
			"Error occurred in GLFW library\n"
			"Error code: " + std::to_string(errCode) + "\n"
			+ errDesc
        );
    }
}