CXX = g++
CXXFLAGS = -m64 -W -Wall -std=c++17
OBJS = Main.o Callbacks.o Logger.o Window.o Renderer.o IRenderable.o
TARGET = SomeFPS.exe
LDFLAGS = -L".\lib"
LDLIBS = -lglfw3dll -lopengl32 -lglew32

${TARGET}: ${OBJS}
	${CXX} ${CXXFLAGS} -g ${OBJS} ${LDFLAGS} ${LDLIBS} -o $@

Main.o: Main.cpp someFPS.hpp
	${CXX} ${CXXFLAGS} -c -g Main.cpp -o Main.o
Callbacks.o: ErrorHandler.cpp logging.hpp callbacks.hpp
	${CXX} ${CXXFLAGS} -c -g ErrorHandler.cpp -o Callbacks.o
Logger.o: Logger.cpp logging.hpp
	${CXX} ${CXXFLAGS} -c -g Logger.cpp -o Logger.o
Window.o: Window.cpp window.hpp
	${CXX} ${CXXFLAGS} -c -g Window.cpp -o Window.o
Renderer.o: Renderer.cpp rendering.hpp
	${CXX} ${CXXFLAGS} -c -g Renderer.cpp -o Renderer.o
IRenderable.o: Irenderable.cpp rendering.hpp
	${CXX} ${CXXFLAGS} -c -g IRenderable.cpp -o IRenderable.o

clean:
	del -f ${TARGET}
	del *.o

.PHONY: clean