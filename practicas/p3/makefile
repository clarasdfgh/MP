BIN = ./bin
INCLUDE = ./include
LIB = ./lib
OBJ = ./obj
SRC = ./src

################################################################################

all : $(BIN)/testArrays $(BIN)/temperatura
	@echo " "

arrays : $(BIN)/testArrays

temperatura : $(BIN)/temperatura

clean :
	@echo "limpiando objetos y bibliotecas..."
	rm obj/*.o
	rm lib/*.a

mrproper : clean
	@echo "limpiando ejecutables..."
	rm bin/*

################################################################################

$(BIN)/testArrays : $(OBJ)/testArrays.o
	@echo "generando ejecutable 'testArrays'..."
	g++ -std=c++0x -o $(BIN)/testArrays $(OBJ)/testArrays.o $(OBJ)/GestionArrays.o

$(BIN)/temperatura : $(OBJ)/temperatura.o $(LIB)/libprac3.a
	@echo "generando ejecutable 'temperatura'..."
	g++ -std=c++0x -o $(BIN)/temperatura $(OBJ)/temperatura.o -L$(LIB) -lprac3

#...............................................................................

$(LIB)/libprac3.a : $(OBJ)/GestionArrays.o $(OBJ)/Calculo.o
	@echo "construyendo biblioteca libprac3..."
	ar rvs $(LIB)/libprac3.a $(OBJ)/GestionArrays.o $(OBJ)/Calculo.o

#...............................................................................

$(OBJ)/testArrays.o : $(SRC)/testArrays.cpp $(OBJ)/GestionArrays.o
	@echo "generando objeto 'testArrays'..."
	g++ -std=c++0x -c -I$(INCLUDE) -o $(OBJ)/testArrays.o $(SRC)/testArrays.cpp

$(OBJ)/GestionArrays.o : $(SRC)/GestionArrays.cpp
	@echo "generando objeto 'GestionArrays'..."
	g++ -std=c++0x -c -I$(INCLUDE) -o $(OBJ)/GestionArrays.o $(SRC)/GestionArrays.cpp

$(OBJ)/temperatura.o : $(SRC)/temperatura.cpp $(OBJ)/Calculo.o
	@echo "generando objeto 'temperatura'..."
	g++ -std=c++0x -c -I$(INCLUDE) -o $(OBJ)/temperatura.o $(SRC)/temperatura.cpp

$(OBJ)/Calculo.o : $(SRC)/Calculo.cpp
	@echo "generando objeto 'Calculo'..."
	g++ -std=c++0x -c -I$(INCLUDE) -o $(OBJ)/Calculo.o $(SRC)/Calculo.cpp
