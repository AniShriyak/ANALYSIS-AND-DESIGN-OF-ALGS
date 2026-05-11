#include <stdio.h>

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int knapsack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if(i == 0 || w == 0)
            {
                K[i][w] = 0;
            }
            else if(wt[i - 1] <= w)
            {
                K[i][w] = max(
                                val[i - 1] + K[i - 1][w - wt[i - 1]],
                                K[i - 1][w]
                             );
            }
            else
            {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    return K[n][W];
}

int main()
{
    int n, W, i;

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];

    // Input values and weights
    for(i = 0; i < n; i++)
    {
        printf("\nEnter value of item %d: ", i + 1);
        scanf("%d", &val[i]);

        printf("Enter weight of item %d: ", i + 1);
        scanf("%d", &wt[i]);
    }

    // Input knapsack capacity
    printf("\nEnter capacity of knapsack: ");
    scanf("%d", &W);

    // Display result
    printf("\nMaximum Profit = %d\n", knapsack(W, wt, val, n));

    return 0;
}
