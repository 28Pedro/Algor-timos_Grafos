TARGET := prim.bin

# Detecta o sistema operacional
ifeq ($(OS),Windows_NT)
    RM := del /Q
    NULL := nul
else
    RM := rm -f
    NULL := /dev/null
endif

# Compilador e flags
CXX := g++
CXXFLAGS := -O3 -flto -std=c++17

# Todos os arquivos-fonte .cpp no diretório atual
SRC := $(wildcard *.cpp)
OBJ := $(SRC:.cpp=.o)

# Regra padrão: compila tudo
all: $(TARGET)

# Linkagem final
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compilação individual
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza — remove apenas arquivos temporários e o binário
clean:
	-$(RM) $(OBJ) $(TARGET) 2>$(NULL) || true

.PHONY: all clean