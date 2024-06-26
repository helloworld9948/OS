#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
    int fd = 3, sz = 4;
    char *c = (char *) calloc(100, sizeof(char));
    
    fd = open("foo.txt", O_RDONLY);
    if (fd < 0) { 
        perror("rl"); 
        exit(1); 
    }
    
    sz = read(fd, c, 10);
    printf("called read(%d, c, 10). returned that %d bytes were read.\n", fd, sz);
    c[sz] = '\0';
    printf("Those bytes are as follows: %s\n", c);
    
    return 0;
}
