#include <stdio.h>
#include <stdlib.h>

// global var
int n, m, max;
int C[10001][10001];


void LCS(int *X, int *Y)
{
    int i, j;
    for (i = 0; i <= n;)
    {
        for (j = 0; j <= m;)
        {
            if (i == 0 || j == 0)
            {
                C[i][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1])
            {
                C[i][j] = C[i - 1][j - 1] + 1;
            } else {
                C[i][j] = C[i - 1][j] > C[i][j - 1] ? C[i -1 ][j] : C[i][j - 1]; 
            }
            ++j;
        }
        ++i;
    }
    max = C[n][m];
}

int main(int argc, char const *argv[])
{
    int *X, *Y;

    scanf("%d", &n);
    scanf("%d", &m);

    X = (int *)malloc(n * sizeof(int));
    Y = (int *)malloc(m * sizeof(int));

    for (int i = 0; i < n;)
    {
        scanf("%d", &X[i]);
        ++i;
    }

    for (int j = 0; j < m;)
    {
        scanf("%d", &Y[j]);
        ++j;
    }

    LCS(X, Y);
    // printf("Result:\n");
    // for (int i = 1; i < n + 1; i++) {
    //     for (int j = 1;j < m + 1; j++) {
    //         printf("%3d", C[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("LSC = %d\n", max);
    printf("%d", max);

    free(X);
    free(Y);
    return 0;
}