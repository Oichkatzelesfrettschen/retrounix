#include <stdint.h>

static inline void outb(uint16_t port, uint8_t val) {
    __asm__ volatile ("outb %0,%1" : : "a"(val), "Nd"(port));
}

static void serial_init(void) {
    outb(0x3F8 + 1, 0x00);
    outb(0x3F8 + 3, 0x80);
    outb(0x3F8 + 0, 0x03);
    outb(0x3F8 + 1, 0x00);
    outb(0x3F8 + 3, 0x03);
    outb(0x3F8 + 2, 0xC7);
    outb(0x3F8 + 4, 0x0B);
}

static void serial_write(const char *s) {
    while (*s)
        outb(0x3F8, *s++);
}

void kmain(void) {
    serial_init();
    serial_write("Retro Unix 64 booted\n");
    for (;;)
        __asm__ volatile ("hlt");
}
