#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = 0;
    while (n <= 0)
    {
        n = get_int("Height: ");
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (j > i)
            {
                printf (" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
