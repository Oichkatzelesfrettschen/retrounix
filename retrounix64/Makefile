NASM ?= nasm
CC   := x86_64-elf-gcc
LD   := x86_64-elf-ld
OBJCOPY := x86_64-elf-objcopy

CFLAGS := -std=c23 -ffreestanding -mno-red-zone -O2 -Wall -Wextra
LDFLAGS := -T kernel/linker.ld -nostdlib

all: kernel.bin

boot.o: kernel/boot.s
	$(NASM) -f elf64 $< -o $@

kernel.o: kernel/main.c
	$(CC) $(CFLAGS) -c $< -o $@

kernel.bin: boot.o kernel.o
	$(LD) $(LDFLAGS) boot.o kernel.o -o kernel.elf
	$(OBJCOPY) -O binary kernel.elf $@

clean:
	rm -f boot.o kernel.o kernel.elf kernel.bin

.PHONY: all clean
