# Author: Hieu_self-study
# #:this is comment in Makefile.
# Define "Variables" so that they can be easily modified later.

#--------------Version 1 Basic of Makefile for Win-------------------------
# CC = gcc
# TARGET = my_cal1.exe
# SOURCES = main.c math_utils.c

# # rules main build (type 'make' will run this section)
# all: 
# 	$(CC) $(SOURCES) -o $(TARGET)
# 	@echo "=> Build success! Run file $(TARGET)"

# # rules run auto
# run: all
# 	@echo "=> Reselts Programming:"
# 	@echo "-----------------------"
# 	./$(TARGET)
# 	@echo "-----------------------"

# # Rules clean old files (type 'make clean' will run this here)
# clean:
# # 	// for Linux
# # 	rm -f $(TARGET) 
# # 	for win /f là ép buộc xóa kể cả file cứng đầu, /q là xóa trong im lặng
# 	del /f /q $(TARGET)
# 	@echo "=> Done clean old file $(TARGET)."


# #--------------Version 2 Upgrade of Makefile for Ubuntu-------------------------
# CC = gcc

# # Paths to folders
# SRC_DIR = src
# INC_DIR = inc
# BIN_DIR = bin

# # add flag -I (Include) to tell GCC how to access the 'inc' directory to find the .h file.
# CFLAGS = -I$(INC_DIR)

# # put the .exe file into the bin folder.
# TARGET = $(BIN_DIR)/my_cal1

# # list file source with new path
# SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/math_utils.c

# # default rules: Create folder bin after then build
# all:
# 	@mkdir -p $(BIN_DIR)
# 	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)
# 	@echo "=> Build success to folder $(BIN_DIR)"

# # run rule programming
# run: all
# 	@echo "=> Result programming:"
# 	@echo "----------------------"
# 	./$(TARGET)
# 	@echo "----------------------"

# # Clean rule all Bin folder
# clean:
# 	@rm -f $(BIN_DIR)/*.exe
# 	@rm -f $(TARGET)
# 	@echo "=> All execution files have been scanned clean!"

#--------------Version 3 Pro Upgrade of Makefile for Ubuntu-------------------------
CC = gcc
CFLAGS = -Iinc -Wall
# Paths to folders
SRC_DIR = src
INC_DIR = inc
BIN_DIR = bin
OBJ_DIR = obj

# scan through all files in the source directory
SOURCES = $(wildcard $(SRC_DIR)/*.c)

# .c to .o in src and point to obj folder
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

# file last target
TARGET = $(BIN_DIR)/my_cal1

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
	@echo "-----------------------"
	./$(TARGET)
	@echo "-----------------------"

# Complete cleanup rules (delete both the bin and obj folders)
clean:
	@rm -rf $(BIN_DIR) $(OBJ_DIR)
	@echo "=> DONE CLEAN -----"
