#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id, weight, profit;
    double ratio;
} Item;

Item items[20];
int n, capacity, maxProfit = 0;
int bestPath[20], currentPath[20];

// Bounding function (Fractional Knapsack)
double getBound(int i, int weight, int profit) {
    if (weight >= capacity) return 0;
    double bound = (double)profit;
    int totalWeight = weight;
    int j = i;

    while (j < n && totalWeight + items[j].weight <= capacity) {
        totalWeight += items[j].weight;
        bound += items[j].profit;
        j++;
    }
    if (j < n) {
        bound += (double)(capacity - totalWeight) * items[j].ratio;
    }
    return bound;
}

// Recursive solver (Silent version)
void solve(int i, int weight, int profit) {
    // Update global maximum if we found a better profit
    if (weight <= capacity && profit > maxProfit) {
        maxProfit = profit;
        for (int k = 0; k < n; k++) bestPath[k] = currentPath[k];
    }

    // Base case or Pruning
    if (i == n || weight > capacity) return;

    // Only branch if the potential (bound) is better than our current best profit
    if (getBound(i, weight, profit) <= maxProfit) return;

    // Branch 1: Include item i
    currentPath[i] = 1;
    solve(i + 1, weight + items[i].weight, profit + items[i].profit);

    // Branch 2: Exclude item i
    currentPath[i] = 0;
    solve(i + 1, weight, profit);
}

int main() {
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter capacity: ");
    scanf("%d", &capacity);

    for (int i = 0; i < n; i++) {
        items[i].id = i + 1;
        printf("Item %d (Weight and Profit): ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].profit);
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }

    // Sort items by ratio (Essential for Branch and Bound efficiency)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    // Run the solver
    solve(0, 0, 0);

    // Final Output only
    printf("\n FINAL OUTPUT\n");
    printf("Max Profit: %d\n", maxProfit);
    printf("Items Included: \n");
    int totalWeight = 0;
    for (int i = 0; i < n; i++) {
        if (bestPath[i]) {
            printf("  - Item No: %d, Weight: %d, Profit: %d\n", items[i].id, items[i].weight, items[i].profit);
            totalWeight += items[i].weight;
        }
    }
    printf("Total Weight used: %d / %d\n", totalWeight, capacity);

    return 0;
}
