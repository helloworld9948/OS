#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME "myfifo"

int main() {
    mkfifo(FIFO_NAME, 0666);
    char arr1[80], arr2[80];
    if (fork() == 0) {
        int fd = open(FIFO_NAME, O_WRONLY);
        write(fd, "Hello", sizeof("Hello"));
        close(fd);
    } else {
        int fd = open(FIFO_NAME, O_RDONLY);
        read(fd, arr1, sizeof(arr1));
        printf("Received: %s\n", arr1);
        close(fd);
        unlink(FIFO_NAME);
    }
    return 0;
}
