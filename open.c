#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

int main() {
    int erno;
    int fd = open("foo.txt", O_RDONLY | O_CREAT);
    printf("fd %d\n", fd);
    if (fd == -1) {
        erno = errno;
        printf("Error Number %d\n", erno);
        perror("Program");
        return 1;
    }
    return 0;
}
