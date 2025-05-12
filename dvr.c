#include <stdio.h>

#define INF 9999

int numRouters;

void updateRoutingTable(int dist[][100], int nextHop[][100]) {
    int updated;
    do {
        updated = 0;  
        for (int i = 0; i < numRouters; i++) {
            for (int j = 0; j < numRouters; j++) {
                for (int k = 0; k < numRouters; k++) {
                    if (dist[i][k] != INF && dist[k][j] != INF &&
                        dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];  
                        nextHop[i][j] = nextHop[i][k];  
                        updated = 1;  
                    }
                }
            }
        }
    } while (updated);  
}

void printRoutingTables(int dist[][100], int nextHop[][100]) {
    for (int i = 0; i < numRouters; i++) {
        printf("\nRouter %d:\n", i);
        printf("Dest  Cost  NextHop\n");
        for (int j = 0; j < numRouters; j++) {
            if (dist[i][j] == INF)
                printf("%d    INF   -\n", j);
            else
                printf("%d    %d     %d\n", j, dist[i][j], nextHop[i][j]);
        }
    }
}

int main() {
    printf("Enter number of routers: ");
    scanf("%d", &numRouters);

    int dist[100][100], nextHop[100][100];

    printf("Enter adjacency matrix (-1 for no direct connection):\n");
    for (int i = 0; i < numRouters; i++) {
        for (int j = 0; j < numRouters; j++) {
            scanf("%d", &dist[i][j]);

            if (dist[i][j] == -1) {
                dist[i][j] = INF;
                nextHop[i][j] = -1;
            } else if (i == j) {
                nextHop[i][j] = -1;
            } else {
                nextHop[i][j] = j;
            }
        }
    }

    updateRoutingTable(dist, nextHop);
    printRoutingTables(dist, nextHop);

    return 0;
}
