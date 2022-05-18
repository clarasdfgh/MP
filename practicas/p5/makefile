BIN = ./bin
INCLUDE = ./include
LIB = ./lib
OBJ = ./obj
SRC = ./src

################################################################################

all : fibonacci lienzo

fibonacci : $(BIN)/fibonacci

lienzo : $(BIN)/lienzo

clean :
	@echo "limpiando objetos y bibliotecas..."
	rm obj/*.o
	rm lib/*.a

mrproper : clean
	@echo "limpiando ejecutables..."
	rm bin/*

# FIBONACCI ####################################################################

$(BIN)/fibonacci : $(OBJ)/fibonacci.o
	@echo "generando ejecutable 'fibonacci'..."
	g++ -std=c++0x -o $(BIN)/fibonacci $(OBJ)/fibonacci.o

$(OBJ)/fibonacci.o : $(SRC)/fibonacci.cpp
	@echo "generando objeto 'fibonacci'..."
	g++ -std=c++0x -c -I$(INCLUDE) -o $(OBJ)/fibonacci.o $(SRC)/fibonacci.cpp

# LIENZO #######################################################################

$(BIN)/lienzo : $(OBJ)/main.o
	@echo "generando ejecutable 'lienzo'..."
	g++ -std=c++0x -o $(BIN)/lienzo -g $(OBJ)/main.o $(OBJ)/lienzo.o

$(OBJ)/main.o : $(SRC)/main.cpp $(OBJ)/lienzo.o
	@echo "generando objeto 'main'..."
	g++ -std=c++0x -c -I$(INCLUDE) -o $(OBJ)/main.o -g $(SRC)/main.cpp

$(OBJ)/lienzo.o : $(SRC)/lienzo.cpp
	@echo "generando objeto 'lienzo'..."
	g++ -std=c++0x -c -I$(INCLUDE) -o $(OBJ)/lienzo.o -g $(SRC)/lienzo.cpp
