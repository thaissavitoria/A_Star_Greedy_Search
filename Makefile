CXX      := g++
CXXFLAGS := -Wall -Wextra
LDFLAGS  := -lstdc++ -lm -std=c++03
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)
TARGET   := app

# Inclui todos os diretórios necessários
INCLUDE  := -I. -IAlgoritmos -IAlgoritmos/Stack -IAlgoritmos/Fifo -IGrafo

# Lista todos os arquivos fonte
SRC      := src/main.cpp \
			Algoritmos/aStar.cpp \
            Algoritmos/greedySearch.cpp \
            Algoritmos/PriorityQueue/pqNode.cpp \
            Algoritmos/PriorityQueue/priorityQueue.cpp \
			Grafo/grafo.cpp
            

# Converte os caminhos dos arquivos fonte para objetos
OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

# Regra para compilar os objetos
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

# Regra para linkar o executável
$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

.PHONY: all build clean debug release run

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)/src
	@mkdir -p $(OBJ_DIR)/Algoritmos/Stack
	@mkdir -p $(OBJ_DIR)/Algoritmos/Fifo
	@mkdir -p $(OBJ_DIR)/Grafo

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O3
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*

run:
	./$(BUILD)/$(TARGET)

# Regra para debug do Makefile
debug-print:
	@echo "Source files:"
	@echo $(SRC)
	@echo "Object files:"
	@echo $(OBJECTS)
	@echo "Include paths:"
	@echo $(INCLUDE)

r: all run