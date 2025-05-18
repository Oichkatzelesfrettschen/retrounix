static inline long sys_write(int fd, const void* buf, unsigned long count){long r; __asm__ __volatile__("syscall" : "=a"(r) : "a"(1), "D"(fd), "S"(buf), "d"(count) : "rcx", "r11", "memory"); return r;}
static inline long sys_read(int fd, void* buf, unsigned long count){long r; __asm__ __volatile__("syscall" : "=a"(r) : "a"(0), "D"(fd), "S"(buf), "d"(count) : "rcx", "r11", "memory"); return r;}
static inline long sys_open(const char* path, int flags, int mode){long r; __asm__ __volatile__("syscall" : "=a"(r) : "a"(2), "D"(path), "S"(flags), "d"(mode) : "rcx", "r11", "memory"); return r;}
static inline long sys_close(int fd){long r; __asm__ __volatile__("syscall" : "=a"(r) : "a"(3), "D"(fd) : "rcx", "r11", "memory"); return r;}
static inline __attribute__((noreturn)) void sys_exit(int status){__asm__ __volatile__("syscall" : : "a"(60), "D"(status) : "rcx", "r11", "memory"); __builtin_unreachable();}
