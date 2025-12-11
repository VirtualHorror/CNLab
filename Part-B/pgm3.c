// Given a graph of 5 nodes A to E, find shortest paths from any node as source to all other nodes using Link state routing.
#include <stdio.h>
#define INF 999

int main() {
    int cost[5][5], dist[5], visited[5] = {0}, i, j, min, u, src;
    printf("Enter cost matrix (5x5, 999 for no link):\n");
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            scanf("%d", &cost[i][j]);
    printf("Enter source (0-4 for A-E): ");
    scanf("%d", &src);
    for (i = 0; i < 5; i++)
        dist[i] = cost[src][i];
    visited[src] = 1;
    for (i = 0; i < 4; i++) {
        min = INF;
        for (j = 0; j < 5; j++)
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        visited[u] = 1;
        for (j = 0; j < 5; j++)
            if (!visited[j] && dist[u] + cost[u][j] < dist[j])
                dist[j] = dist[u] + cost[u][j];
    }
    printf("Shortest distances from %c:\n", 'A' + src);
    for (i = 0; i < 5; i++)
        printf("To %c: %d\n", 'A' + i, dist[i]);
    return 0;
}
