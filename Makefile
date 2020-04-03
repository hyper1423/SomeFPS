CXX = g++
CXXFLAGS = -m64 -W -Wall
OBJS = Main.o Callbacks.o Logger.o Window.o Renderer.o
TARGET = SomeFPS.exe
LDFLAGS = -L".\lib"
LDLIBS = -lglfw3dll -lglew32

${TARGET}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} ${LDFLAGS} ${LDLIBS} -o $@

Main.o: Main.cpp someFPS.hpp
	${CXX} ${CXXFLAGS} -c Main.cpp -o Main.o
Callbacks.o: Callbacks.cpp logging.hpp callbacks.hpp
	${CXX} ${CXXFLAGS} -c Callbacks.cpp -o Callbacks.o
Logger.o: Logger.cpp logging.hpp
	${CXX} ${CXXFLAGS} -c Logger.cpp -o Logger.o
Window.o: Window.cpp window.hpp
	${CXX} ${CXXFLAGS} -c Window.cpp -o Window.o
Renderer.o: Renderer.cpp render.hpp
	${CXX} ${CXXFLAGS} -c Renderer.cpp -o Renderer.o

clean:
	del -f ${TARGET}
	del *.o

.PHONY: clean