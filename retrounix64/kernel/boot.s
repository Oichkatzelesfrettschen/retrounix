.section .text
.global start
.code16
start:
    cli
    xor %ax, %ax
    mov %ds, %ax
    mov %ss, %ax
    mov $0x7c00, %sp

    lgdt gdt_desc

    mov %cr0, %eax
    or $1, %eax
    mov %eax, %cr0
    ljmp $0x08, $protected

.code32
protected:
    mov $0x10, %ax
    mov %ds, %ax
    mov %ss, %ax
    mov $0x90000, %esp

    mov %cr4, %eax
    or $0x20, %eax
    mov %eax, %cr4

    mov $pml4, %eax
    mov %eax, %cr3

    mov $0xc0000080, %ecx
    rdmsr
    or $0x100, %eax
    wrmsr

    mov %cr0, %eax
    or $0x80000001, %eax
    mov %eax, %cr0

    ljmp $0x08, $longmode

.code64
longmode:
    mov $0x10, %rax
    mov %ds, %ax
    mov %ss, %ax
    mov $stack_top, %rsp

    call kmain

halt:
    hlt
    jmp halt

.align 16
gdt:
    .quad 0
    .quad 0x00af9a000000ffff
    .quad 0x00af92000000ffff
gdt_desc:
    .word gdt_end - gdt - 1
    .long gdt
gdt_end:

.align 4096
pml4:
    .quad pdpt | 3
    .fill 511,8,0
pdpt:
    .quad pd | 3
    .fill 511,8,0
pd:
    .quad 0x0000000000000083
    .fill 511,8,0

.section .bss
.align 16
stack:
    .skip 4096
stack_top:
