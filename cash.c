#include<cs50.h>
#include<stdio.h>

int main(void)
{

    int n = -1;
    while(n < 0)
    {
        n = get_int("Changed owed: ");
    }
    int res = 0;
    while(n > 0)
    {
        if (n >= 25)
        {
            res++;
            n -= 25;
        }
        else if (n >= 10)
        {
            res++;
            n -= 10;
        }
        else if (n >= 5)
        {
            res++;
            n -= 5;
        }
        else
        {
            res++;
            n--;
        }
    }
    printf("%i\n", res);
}
