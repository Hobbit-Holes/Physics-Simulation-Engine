OBJS = main.cpp
CPPS = ./../../engine/*.cpp
OBJ_NAME = exercise-04.exe
CPP = g++
INCLUDE_PATHS = -IC:\mingw_dev_lib\include -I./../../engine/
LIBRARY_PATHS = -LC:\mingw_dev_lib\lib
COMPILER_FLAGS = -std=c++17 -Wall
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2

build:
	$(CPP) $(OBJS) $(CPPS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)