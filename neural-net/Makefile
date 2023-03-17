SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
SDL_DIR := /opt/homebrew/Cellar

EXE := $(BIN_DIR)/main
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CXX       := g++
TARGET    := -target arm64-apple-macos11
FRAMEWORK := -framework ApplicationServices
CPPFLAGS  := -Iinc -MMD -MP
CXXFLAGS  := -Wall -Wextra -std=c++2a -ggdb $(TARGET)
LDFLAGS   := 
LDLIBS    := 

.PHONY: all clean run

all: $(EXE)

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) $(TARGET) $(FRAMEWORK) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)

run:
	$(EXE) weight.dat input.dat

-include $(OBJ:.o=.d)