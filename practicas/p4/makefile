BIN = ./bin
INCLUDE = ./include
LIB = ./lib
OBJ = ./obj
SRC = ./src

#########################################################

all : $(BIN)/p4

clean :
	@echo "limpiando objetos y bibliotecas..."
	rm obj/*.o
	rm lib/*.a

mrproper : clean
	@echo "limpiando ejecutables..."
	rm bin/*

#########################################################

$(BIN)/p4 : $(OBJ)/p4.o
	@echo "generando ejecutable 'p4'..."
	g++ -std=c++0x -o $(BIN)/p4 $(OBJ)/p4.o $(OBJ)/func_p4.o

$(OBJ)/p4.o : $(SRC)/p4.cpp $(OBJ)/func_p4.o
	@echo "generando objeto 'p4'..."
	g++ -std=c++0x -c -I$(INCLUDE) -o $(OBJ)/p4.o $(SRC)/p4.cpp

$(OBJ)/func_p4.o : $(SRC)/func_p4.cpp
	@echo "generando objeto 'func_p4'..."
	g++ -std=c++0x -c -I$(INCLUDE) -o $(OBJ)/func_p4.o $(SRC)/func_p4.cpp
