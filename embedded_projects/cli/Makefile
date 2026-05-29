# Author: Hieu_self-study

CC = gcc
CFLAGS = -IInc -Wall
# Paths to folders
SRC_DIR = Src
INC_DIR = Inc
BIN_DIR = Bin
OBJ_DIR = Obj

# scan through all files in the source directory
SOURCES = $(wildcard $(SRC_DIR)/*.c)

# .c to .o in src and point to obj folder
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

# file last target
TARGET = $(BIN_DIR)/uart_frame

# ==========================================
# 				RULES
# ==========================================

# default rule
all: $(TARGET)

# Rule 1 (LINKER): connect file .o to complete file
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) -o $@
	@echo "[LINK] The executable file has been successfully created $@"

# Rule 2 (COMPILER): shifting file .c to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "=> [BUILD] Compiled $<"

# Run rule programming
run: all
	@echo "=> ----------RESULT PROGRAMING----------"
	./$(TARGET)
	@echo "-----------------------"

# Complete cleanup rules (delete both the bin and obj folders)
clean:
	@rm -rf $(BIN_DIR) $(OBJ_DIR)
	@echo "=> DONE CLEAN -----"
