#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to compute the maximum value obtainable with a given weight capacity
int knapSack(int W, int weights[], int values[], int n) {
    int i, w;

    int **K = (int **)malloc((n + 1) * sizeof(int *));
    for (i = 0; i <= n; i++) {
        K[i] = (int *)malloc((W + 1) * sizeof(int));
    }

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

    int result = K[n][W];

    // Free the allocated memory
    for (i = 0; i <= n; i++) {
        free(K[i]);
    }
    free(K);

    return result;
}

int main() {
    int n, W;

    // Read number of items
    printf("Number of items:\n");
    scanf("%d", &n);

    int *values = (int *)malloc(n * sizeof(int));
    int *weights = (int *)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (!values || !weights) {
        printf("Failed to allocate memory\n");
        return 1;  // Exit with an error code
    }

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

    // Free the allocated memory
    free(values);
    free(weights);

    return 0;
}

