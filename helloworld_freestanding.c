static inline int sys_write(const int fd, const void *buf, const unsigned int count)
{
    int ret;
    asm volatile ("syscall;" : "=a"(ret) : "a"(1), "D"(fd), "S"(buf), "d"(count)/* : "cc", "%rax", "%rdi", "%rsi"*/);
    return ret;
}

static inline void sys_exit(int status)
{
    asm volatile ("syscall;" : : "a"(60), "D"(status));
}

unsigned int strlen(const char *str)
{
    unsigned int i = 0;

    for (; str[i] ; i++) {}

    return i;
}

int print(const char *str)
{
    return sys_write(1, str, strlen(str));
}

int main(void)
{
    print("Hello World!\n");
    sys_exit(0);
    return 0;
}

