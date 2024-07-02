#include <stdio.h>

int main(void)
{
    int n, i, j, k;
    do
    {
        printf("Height: ");
        scanf("%i", &n);
    }
    while ((1 > n) || (n > 8));

    for (i = 0; i < n; i++)
    {
        for (j = n - 1 - i; 0 < j; j--)
        {
            printf(" ");
        }
        for (k = i + 1; 0 < k; k--)
        {
            printf("#");
        }

        printf("  ");

        for (k = i + 1; 0 < k; k--)
        {
            printf("#");
        }

        printf("\n");
    }
}
