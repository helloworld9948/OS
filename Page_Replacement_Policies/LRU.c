#include <stdio.h>

int main() {
    int n, m, frame[10], pages[30], count[10], time = 0, min, pos, flag, count_fault = 0;
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
        for(int j = 0; j < m; j++) {
            if(frame[j] == pages[i]) {
                flag = 1;
                count[j] = time++;
            }
        }
        if(flag == 0) {
            if(i < m) {
                frame[i] = pages[i];
                count[i] = time++;
            } else {
                min = count[0];
                pos = 0;
                for(int j = 1; j < m; j++) {
                    if(count[j] < min) {
                        min = count[j];
                        pos = j;
                    }
                }
                frame[pos] = pages[i];
                count[pos] = time++;
            }
            count_fault++;
        }
        for(int j = 0; j < m; j++)
            printf("%d ", frame[j]);
        printf("\n");
    }
    printf("Page faults: %d\n", count_fault);
    return 0;
}
