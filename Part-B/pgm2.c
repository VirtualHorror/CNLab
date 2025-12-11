// Given a graph of 5 nodes A to E, find shortest paths from any node as source to all other
nodes using Distance vector routing.
#include <stdio.h>
#define INF 999

int main() {
    int cost[5][5], dist[5][5], next[5][5], i, j, k;
    printf("Enter cost matrix (5x5, 999 for no link):\n");
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++) {
            scanf("%d", &cost[i][j]);
            dist[i][j] = cost[i][j];
            next[i][j] = j;
        }
    for (k = 0; k < 5; k++)
        for (i = 0; i < 5; i++)
            for (j = 0; j < 5; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
    int src;
    printf("Enter source node (0-4 for A-E): ");
    scanf("%d", &src);
    printf("From %c:\n", 'A' + src);
    for (j = 0; j < 5; j++)
        if (j != src)
            printf("To %c: Distance=%d, Via=%c\n", 'A' + j, dist[src][j], 'A' + next[src][j]);
    return 0;
}
