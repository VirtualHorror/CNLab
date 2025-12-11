// Packets from different flows arrive at a switch or router for processing. A good scheduling technique treats the different flows in a fair and appropriate manner. Implement priority queuing as a technique to improve Quality of Service.
#include <stdio.h>

int high[10], med[10], low[10], hc = 0, mc = 0, lc = 0;

void enqueue(int pkt, int pri) {
    if (pri == 1) high[hc++] = pkt;
    else if (pri == 2) med[mc++] = pkt;
    else low[lc++] = pkt;
}

int dequeue() {
    if (hc > 0) return high[--hc];
    if (mc > 0) return med[--mc];
    if (lc > 0) return low[--lc];
    return -1;
}

int main() {
    int n, pkt, pri, i;
    printf("Enter number of packets: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Packet ID and Priority (1=High,2=Med,3=Low): ");
        scanf("%d %d", &pkt, &pri);
        enqueue(pkt, pri);
    }
    printf("Processing order:\n");
    for (i = 0; i < n; i++)
        printf("Packet %d\n", dequeue());
    return 0;
}
