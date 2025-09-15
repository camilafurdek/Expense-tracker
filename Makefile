CC = g++
CCFLAGS = -Wall -Wextra -std=c++17 -MMD -MP

SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

TARGET = $(BIN_DIR)/expense-tracker

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)

# Regla principal
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CCFLAGS) -o $@ $(OBJS)

# Regla para compilar cada .cpp
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CCFLAGS) -c $< -o $@

# Limpieza
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Incluir dependencias generadas, al final
-include $(DEPS)
