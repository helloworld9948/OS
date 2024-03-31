#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char *file;
    int fd;
    struct flock lock;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = argv[1];

    printf("opening %s\n", file);

    fd = open(file, O_WRONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    printf("locking\n");

    memset(&lock, 0, sizeof(lock));
    lock.l_type = F_WRLCK;

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("locked; hit Enter to unlock...");
    getchar();

    printf("unlocking\n");
    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    close(fd);

    return 0;
}
