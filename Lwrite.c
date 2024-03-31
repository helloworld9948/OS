#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int sz;
    int fd = open("foo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    
    if (fd < 0) {
        perror("rl");
        exit(1);
    }
    
    sz = write(fd, "hello geeks\n", strlen("hello geeks\n"));
    printf("called write (%d, \"hello geeks\\n\", %d). It returned %d\n", fd, strlen("hello geeks\n"), sz);
    close(fd);
    
    return 0;
}
