BIN = ./bin
INCLUDE = ./include
LIB = ./lib
OBJ = ./obj
SRC = ./src

#########################################################

all : $(BIN)/compra

clean :
	@echo "limpiando objetos y bibliotecas..."
	rm obj/*.o
	rm lib/*.a

mrproper : clean
	@echo "limpiando ejecutables..."
	rm bin/*

#########################################################

$(BIN)/compra : $(OBJ)/compra.o
	@echo "generando ejecutable 'compra'..."
	g++ -std=c++0x -o $(BIN)/compra $(OBJ)/compra.o $(OBJ)/ListaCompra.o

$(OBJ)/compra.o : $(SRC)/compra.cpp $(OBJ)/ListaCompra.o
	@echo "generando objeto 'compra'..."
	g++ -std=c++0x -c -I$(INCLUDE) -o $(OBJ)/compra.o $(SRC)/compra.cpp

$(OBJ)/ListaCompra.o : $(SRC)/ListaCompra.cpp
	@echo "generando objeto 'ListaCompra'..."
	g++ -std=c++0x -c -I$(INCLUDE) -o $(OBJ)/ListaCompra.o $(SRC)/ListaCompra.cpp
