#include <stdio.h>
#define INF 99999
#define MAX 100
void printMatrix(int dist[MAX][MAX], int V) {
    int i, j;
    printf("\nShortest distance matrix:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (dist[i][j] >= INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int V, i, j, k, val;
    int dist[MAX][MAX];

    printf("Enter the number of vertices: ");
    if (scanf("%d", &V) != 1) return 0;

    printf("Enter the adjacency matrix (0 for no edge, except diagonal):\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (scanf("%d", &val) != 1) return 0;

            if (i == j) {
                dist[i][j] = 0;
            } else if (val == 0) {
                dist[i][j] = INF;
            } else {
                dist[i][j] = val;
            }
        }
    }

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printMatrix(dist, V);

    return 0;
}
