#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
int main(int argc, char * argv[])
{
    if (argc != 2)
    {
        printf("Error\n");
        return 1;
    }
    else
    {
        int len = 0;
        int alphabet[26] = {0};
        char c;
        while (argv[1][len] != '\0')
        {
            c = argv[1][len];
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            {
                c = toupper(c);
                int index = c - 'A';
                alphabet[index]++;
            }
            else
            {
                printf("Error\n");
                return 1;
            }
            len++;
        }
        if (len != 26)
        {
            printf("Error\n");
            return 1;
        }
        for(int i = 0; i < 26; i++)
        {
            if (alphabet[i] != 1)
            {
                printf("Error\n");
                return 1;
            }
        }
    }
    int sub[26];
    for(int i = 0; i < 26; i++)
    {
        sub[i] = toupper(argv[1][i]);
    }
    int i = 0;
    string plain = get_string("plaintext: ");
    while (plain[i] != '\0')
    {
        if (plain[i] >= 'A' && plain[i] <= 'Z')
        {
            plain[i] = sub[plain[i] - 'A'];
        }
        else if (plain[i] >= 'a' && plain[i] <= 'z')
        {
            plain[i] = tolower(sub[plain[i] - 'a']);
        }
        i++;
    }
    printf("ciphertext: %s\n", plain);
    return 0;
}
