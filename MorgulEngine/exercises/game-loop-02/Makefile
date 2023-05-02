OBJS = main.cpp
CCPS = ./../../engine/*.cpp
OBJ_NAME = game-loop-02.exe
CPP = g++
INCLUDE_PATHS = -IC:\mingw_dev_lib\include -I./../../engine/ -I./../../libs/
LIBRARY_PATHS = -LC:\mingw_dev_lib\lib
COMPILER_FLAGS = -std=c++17 -Wall
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -llua53 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

build:
	$(CPP) $(OBJS) $(CCPS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)