CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -g

SRCS = langtonMain.cpp ant.cpp menu.cpp
OBJS = ${SRCS: .cpp = .o}
HEADERS = ant.hpp menu.hpp

MAIN = langton

all: ${MAIN}
	@echo sucessfully compiled!

${MAIN}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${MAIN}

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	${RM} ${PROGS} ${OBJS} *.0 *~.
