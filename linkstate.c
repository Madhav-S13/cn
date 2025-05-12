#include <stdio.h>
#define INF 9999
#define MAX 100

int numRouters;

// Function to find the unvisited node with the smallest distance
int minDistance(int dist[], int visited[]) {
    int min = INF, index = -1;
    for (int i = 0; i < numRouters; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

// Dijkstra's algorithm for one router
void dijkstra(int graph[MAX][MAX], int src, int dist[], int prev[]) {
    int visited[MAX] = {0};

    for (int i = 0; i < numRouters; i++) {
        dist[i] = INF;
        prev[i] = -1;
    }
    dist[src] = 0;

    for (int count = 0; count < numRouters - 1; count++) {
        int u = minDistance(dist, visited);
        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < numRouters; v++) {
            if (!visited[v] && graph[u][v] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }
}

// Function to print the routing table of one router
void printRoutingTable(int src, int dist[], int prev[]) {
    printf("\nRouter %d:\n", src);
    printf("Dest  Cost  NextHop\n");
    for (int i = 0; i < numRouters; i++) {
        if (dist[i] == INF)
            printf("%d     INF   -\n", i);
        else if (i == src)
            printf("%d     0     -\n", i);
        else {
            int nextHop = i;
            while (prev[nextHop] != src && prev[nextHop] != -1)
                nextHop = prev[nextHop];
            if (prev[i] == -1)
                printf("%d     %d     -\n", i, dist[i]);
            else
                printf("%d     %d     %d\n", i, dist[i], nextHop);
        }
    }
}

// Main function
int main() {
    int graph[MAX][MAX];
    printf("Enter number of routers: ");
    scanf("%d", &numRouters);

    printf("Enter adjacency matrix (-1 for no direct connection):\n");
    for (int i = 0; i < numRouters; i++) {
        for (int j = 0; j < numRouters; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == -1)
                graph[i][j] = INF;
        }
    }

    // Run Dijkstra's algorithm for each router
    for (int i = 0; i < numRouters; i++) {
        int dist[MAX], prev[MAX];
        dijkstra(graph, i, dist, prev);
        printRoutingTable(i, dist, prev);
    }

    return 0;
}
