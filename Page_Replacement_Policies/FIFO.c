#include <stdio.h>

int main() {
    int n, frame[10], pages[30], m, k = 0, flag, count = 0;
    printf("Enter number of frames: ");
    scanf("%d", &m);
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter reference string: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    for(int i = 0; i < m; i++)
        frame[i] = -1;
    for(int i = 0; i < n; i++) {
        flag = 0;
        for(int j = 0; j < m; j++)
            if(frame[j] == pages[i])
                flag = 1;
        if(flag == 0) {
            frame[k] = pages[i];
            k = (k + 1) % m;
            count++;
        }
        for(int j = 0; j < m; j++)
            printf("%d ", frame[j]);
        printf("\n");
    }
    printf("Page faults: %d\n", count);
    return 0;
}
