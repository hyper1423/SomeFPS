// Uhhhhh...s
// I know singletons cause a lot of bad thing, but I had to use this to optimize, sorry.
#include "include/GL/glew.h"

#include <optional>

class StateManager {
public:
	static StateManager& getInstance();
	void bindVertexBuffer(GLenum type, GLuint vertexBufferID);
	void bindVertexArray(GLuint vertexArrayID);

private:
	StateManager();

	static std::optional<StateManager> instance;

	GLuint vertexBufferCache = (GLuint) nullptr;
	GLuint vertexArrayCache = (GLuint) nullptr;
};