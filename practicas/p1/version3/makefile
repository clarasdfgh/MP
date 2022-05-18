BIN = ./bin
INCLUDE = ./include
LIB = ./lib
OBJ = ./obj
SRC = ./src

#########################################################

all : $(BIN)/central

clean : 
	@echo "limpiando objetos y bibliotecas..."
	rm obj/*.o
	rm lib/*.a
	
mrproper : clean
	@echo "limpiando ejecutables..."
	rm bin/*

#########################################################
	
	
$(BIN)/central : $(OBJ)/central.o $(LIB)/libformas.a
	@echo "generando ejecutable central..."
	g++ -o $(BIN)/central $(OBJ)/central.o -L$(LIB) -lformas
	
$(LIB)/libformas.a : $(OBJ)/circulo.o $(OBJ)/punto2d.o
	@echo "construyendo biblioteca libformas..."
	ar rvs $(LIB)/libformas.a $(OBJ)/circulo.o $(OBJ)/punto2d.o
	
$(OBJ)/central.o : $(SRC)/central.cpp $(OBJ)/punto2d.o $(OBJ)/circulo.o
	@echo "generando código objeto central..."
	g++ -c -I$(INCLUDE) -o $(OBJ)/central.o $(SRC)/central.cpp
	
$(OBJ)/circulo.o : $(SRC)/circulo.cpp $(OBJ)/punto2d.o
	@echo "generando código objeto circulo..."
	g++ -c -I$(INCLUDE) -o $(OBJ)/circulo.o $(SRC)/circulo.cpp
	
$(OBJ)/punto2d.o : $(SRC)/punto2d.cpp 
	@echo "generando código objeto punto2d..."
	g++ -c -I$(INCLUDE) -o $(OBJ)/punto2d.o $(SRC)/punto2d.cpp




	
