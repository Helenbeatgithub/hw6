#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to compute the maximum value obtainable with a given weight capacity
int knapSack(int W, int weights[], int values[], int n) {
    int i, w;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i - 1] <= w)
                K[i][w] = max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main() {
    int n, W;

    // Read number of items
    printf("Number of items:\n");
    scanf("%d", &n);

    int values[n], weights[n];

    // Read item values
    printf("Item values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    // Read item weights
    printf("Item weights:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    // Read knapsack weight capacity
    printf("Knapsack weight capacity:\n");
    scanf("%d", &W);

    printf("Answer: Maximum value:\n%d\n", knapSack(W, weights, values, n));

    return 0;
}
