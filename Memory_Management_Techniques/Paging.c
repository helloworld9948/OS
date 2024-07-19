#include <stdio.h>

int main() {
    int n, m, i, j, page[20], frame[10], k, avail, count = 0;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page numbers: ");
    for(i = 0; i < n; i++)
        scanf("%d", &page[i]);
    printf("Enter number of frames: ");
    scanf("%d", &m);
    for(i = 0; i < m; i++)
        frame[i] = -1;
    j = 0;
    printf("Page frames\n");
    for(i = 0; i < n; i++) {
        avail = 0;
        for(k = 0; k < m; k++)
            if(frame[k] == page[i])
                avail = 1;
        if(avail == 0) {
            frame[j] = page[i];
            j = (j + 1) % m;
            count++;
            for(k = 0; k < m; k++)
                printf("%d ", frame[k]);
        }
        printf("\n");
    }
    printf("Page faults: %d\n", count);
    return 0;
}
