# This is the name that our final kernel executable will have.
# Change as needed.
TARGET := myos.elf
 
# It is highly recommended to use a custom built cross toolchain to build a kernel.
# We are only using "cc" as a placeholder here. It may work by using
# the host system's toolchain, but this is not guaranteed.
CC = cc
ASMC = nasm
# User controllable CFLAGS.
CFLAGS = -Wall -Wextra -O2 -pipe
ASMFLAGS = 
# Internal link flags that should not be changed by the user.
LDINTERNALFLAGS :=  \
	-Tlinker.ld \
	-static     \
	-nostdlib   \
	-no-pie
 
# Internal C flags that should not be changed by the user.
INTERNALCFLAGS  :=           \
	-I.                  \
	-ffreestanding       \
	-fno-stack-protector \
	-fno-pic             \
	-mno-80387           \
	-mno-mmx             \
	-mno-3dnow           \
	-mno-sse             \
	-mno-sse2            \
	-mcmodel=kernel      \
	-mno-red-zone
 
# Use find to glob all *.c files in the directory and extract the object names.
CFILES := $(shell find ./ -type f -name '*.c')
ASMFILES := $(shell find ./ -type f -name '*.asm')
OBJ    := $(CFILES:.c=.o)
OBJ    += $(ASMFILES:.asm=._asm)
 
# Targets that do not actually build a file of the same name.
.PHONY: all clean
 
# Default target.
all: $(TARGET)
 
# Link rules for the final kernel executable.
$(TARGET): $(OBJ)
	$(CC) $(LDINTERNALFLAGS) $(OBJ) -o $@
 
# Compilation rules for *.c files.
%.o: %.c
	$(CC) $(CFLAGS) $(INTERNALCFLAGS) -c $< -o $@
 
%._asm: %.asm
	$(ASMC) $(ASMFLAGS) $^ -f elf64 -o $@
 
# Remove object files and the final executable.
clean:
	rm -rf $(TARGET) $(OBJ)
