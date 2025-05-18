CC ?= gcc
CFLAGS = -std=c2x -O2 -nostdlib -ffreestanding -static

BINARIES = usr/bin/cat usr/bin/echo

all: $(BINARIES)

usr/bin/cat: usr/bin/start.S usr/bin/cat.c usr/bin/sys.h
$(CC) $(CFLAGS) usr/bin/start.S usr/bin/cat.c -o $@

usr/bin/echo: usr/bin/start.S usr/bin/echo.c usr/bin/sys.h
$(CC) $(CFLAGS) usr/bin/start.S usr/bin/echo.c -o $@

clean:
rm -f $(BINARIES)

.PHONY: all clean
