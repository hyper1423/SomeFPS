CXX = g++
CXXFLAGS = -m64 -W -Wall
OBJS = Main.o Callbacks.o Logger.o RenderContext.o
TARGET = SomeFPS.exe
LDFLAGS = -L".\lib"
LDLIBS = -lglfw3dll -lglew32

${TARGET}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} ${LDFLAGS} ${LDLIBS} -o $@

Main.o: Main.cpp someFPS.hpp
	${CXX} ${CXXFLAGS} -c Main.cpp -o Main.o
Callbacks.o: Callbacks.cpp someFPS.hpp
	${CXX} ${CXXFLAGS} -c Callbacks.cpp -o Callbacks.o
Logger.o: Logger.cpp someFPS.hpp
	${CXX} ${CXXFLAGS} -c Logger.cpp -o Logger.o
RenderContext.o: RenderContext.cpp someFPS.hpp
	${CXX} ${CXXFLAGS} -c RenderContext.cpp -o RenderContext.o

clean:
	del -f ${TARGET}
	del *.o

.PHONY: clean