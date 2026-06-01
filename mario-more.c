#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = 0;
    while (n <= 0 || n > 8)
    {
        n = get_int("Height: ");
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + i + 3; j++)
        {
            if (j == n || j == n + 1 || j - i > n + 2 || i + j + 1 < n)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
