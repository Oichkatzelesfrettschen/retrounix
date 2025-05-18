# Retro Unix 64 (experimental)

This folder contains a very small 64-bit proof of concept kernel.  It is
built using a cross compiler that targets the `x86_64-elf` ABI.

## Building

A toolchain providing `x86_64-elf-gcc` and related utilities must be
installed and accessible from the `PATH`.

```
$ cd retrounix64
$ make
```

The resulting `kernel.bin` can be executed with QEMU:

```
$ qemu-system-x86_64 -kernel kernel.bin -serial stdio
```

A short banner should appear on the serial console.
