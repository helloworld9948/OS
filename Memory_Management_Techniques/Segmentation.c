#include <stdio.h>

struct segment {
    int base;
    int limit;
} seg[20];

int main() {
    int n, logical, offset, physical;
    printf("Enter number of segments: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Enter base and limit of segment %d: ", i);
        scanf("%d %d", &seg[i].base, &seg[i].limit);
    }
    printf("Enter logical address (segment no, offset): ");
    scanf("%d %d", &logical, &offset);
    if(offset < seg[logical].limit) {
        physical = seg[logical].base + offset;
        printf("Physical address: %d\n", physical);
    } else {
        printf("Invalid address\n");
    }
    return 0;
}
