#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int a[2];
    char buff[10];
    if (pipe(a) == -1) {
        perror("pipe");
        exit(1);
    }
    write(a[1], "code", 5);
    read(a[0], buff, 5);
    printf("%s\n", buff);
    return 0;
}
