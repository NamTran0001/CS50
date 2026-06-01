#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long n = get_long("Number: ");
    int res = 0;
    int pos = 1;
    int temp = 0;
    long first_two = n;
    while (first_two >= 100)
    {
        first_two /= 10;
    }
    while (n > 0)
    {
        temp = n % 10;
        if (pos % 2 == 0)
        {
            temp *= 2;
            if (temp >= 10)
            {
                temp = temp % 10 + temp / 10;
            }
            res += temp;
        }
        else
        {
            res += temp;
        }
        n /= 10;
        pos++;
    }
    res %= 10;
    if(res == 0)
    {
        if (pos == 16 && (first_two == 34 || first_two == 37))
        {
            printf("AMEX\n");
        }
        else if ((pos == 14 || pos == 17) && (first_two / 10) == 4)
        {
            printf("VISA\n");
        }
        else if (pos == 17 && (first_two >= 51 && first_two <= 55))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
