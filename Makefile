# Compiler and Flags
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude

# Directories
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

# Target Executable
TARGET := $(BIN_DIR)/TitanSecurity

# Source Files: Excludes any files in the root (like bad_design.cpp)
# Only grabs .cpp files from the src/ folder
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Default Rule
all: $(TARGET)

# Link the modular components
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJS) -o $(TARGET)
	@echo "Build successful: $(TARGET)"

# Compile modular source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean artifacts
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "Cleaned project files."

# Run the 'Good Design' simulation
run: all
	./$(TARGET)

.PHONY: all clean run