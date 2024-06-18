// kernel.c

#include "vga.h"
#include "idt.h"
#include "io.h"
#include "shell.h"

// Kernel entry point
void kernel_main() {
    // Initialize VGA for text output
    vga_init();
    vga_clear();

    // Initialize IDT
    idt_init();

    // Display a welcome message
    vga_write_string("Welcome to Nemesis OS!\n");

    // Initialize and start the shell
    shell_init();
    shell_run();

    // Halt the CPU indefinitely
    while (1) {
        asm volatile ("hlt");
    }
}
