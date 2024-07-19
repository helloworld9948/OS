#include <stdio.h>

int fr[3], n, m;

void display() {
    for (int i = 0; i < m; i++)
        printf("%d\t", fr[i]);
    printf("\n");
}

int main() {
    int i, j, page[20], lg[3], pf = 0;

    printf("Enter length of the reference string: ");
    scanf("%d", &n);
    printf("Enter the reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &page[i]);
    printf("Enter number of frames: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++)
        fr[i] = -1;
    pf = m;

    for (j = 0; j < n; j++) {
        int flag1 = 0, flag2 = 0;
        for (i = 0; i < m; i++) {
            if (fr[i] == page[j]) {
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }

        if (!flag1) {
            for (i = 0; i < m; i++) {
                if (fr[i] == -1) {
                    fr[i] = page[j];
                    flag2 = 1;
                    break;
                }
            }
        }

        if (!flag2) {
            for (i = 0; i < m; i++)
                lg[i] = 0;

            for (i = 0; i < m; i++) {
                for (int k = j + 1; k < n; k++) {
                    if (fr[i] == page[k]) {
                        lg[i] = k - j;
                        break;
                    }
                }
            }

            int max = lg[0], index = 0;
            for (i = 1; i < m; i++) {
                if (lg[i] == 0) {
                    index = i;
                    break;
                } else if (lg[i] > max) {
                    max = lg[i];
                    index = i;
                }
            }
            fr[index] = page[j];
            pf++;
        }
        display();
    }

    printf("Number of page faults: %d\n", pf);
    printf("Page fault rate: %.2f%%\n", (float)pf / n * 100);
    return 0;
}
