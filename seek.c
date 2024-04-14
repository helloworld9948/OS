#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = 0;
    char ch = '\0';
    
    fd = open("test.dat", O_RDONLY);

    while (read(fd, &ch, 1) != 0)
        printf("%c", ch);
    printf("\n");
    
    lseek(fd, 0, SEEK_SET); // Corrected function name to lseek
    sleep(5);
    
    return 0;
}
