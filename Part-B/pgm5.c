// Write a program to achieve Traffic management at Flow level by implementing Leaky Bucket Algorithm.
#include <stdio.h>

int main() {
    int bucket = 0, cap, rate, n, i, pkt;
    printf("Enter bucket capacity: ");
    scanf("%d", &cap);
    printf("Enter output rate: ");
    scanf("%d", &rate);
    printf("Enter number of time units: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Packets arriving at time %d: ", i + 1);
        scanf("%d", &pkt);
        bucket += pkt;
        if (bucket > cap) {
            printf("Overflow! %d packets dropped\n", bucket - cap);
            bucket = cap;
        }
        int out = (bucket < rate) ? bucket : rate;
        bucket -= out;
        printf("Sent: %d, Bucket: %d\n", out, bucket);
    }
    return 0;
}
