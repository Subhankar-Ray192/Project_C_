void _start() {
    // File descriptor for stdout
    const int STDOUT_FILENO = 1;

    // Your "Hello World" string
    const char hello[] = "Hello World\n";

    // System call number for write
    const long syscall_write = 1;

    // Inline assembly to invoke the write system call
    asm volatile (
        "mov %0, %%rdi\n"   // File descriptor: STDOUT_FILENO
        "mov %1, %%rsi\n"   // Buffer address: hello
        "mov %2, %%rdx\n"   // Number of bytes to write: sizeof(hello) - 1
        "mov %3, %%rax\n"   // System call number: syscall_write
        "syscall\n"         // Invoke the system call
        "mov %4, %%rdi\n"   // Exit status: 0
        "mov %5, %%rax\n"   // System call number: syscall_exit
        "syscall\n"         // Invoke the system call
        :
        : "g"(STDOUT_FILENO), "g"(hello), "g"(sizeof(hello) - 1),
          "g"(syscall_write), "g"(0), "g"(60)  // syscall_exit = 60
        : "rdi", "rsi", "rdx", "rax"
    );
}

