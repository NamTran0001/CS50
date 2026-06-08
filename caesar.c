#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int j = 0;
    while(argv[1][j] != '\0')
    {
        if (!isdigit(argv[1][j]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        j++;
    }
    string plain = get_string("plaintext: ");
    int key = atoi(argv[1]);
    int i = 0;
    while(plain[i] != '\0')
    {
        if (plain[i] >= 'A' && plain[i] <= 'Z')
        {
            plain[i] = ((plain[i] - 'A' + key) % 26) + 'A';
        }
        else if (plain[i] >= 'a' && plain[i] <= 'z')
        {
            plain[i] = ((plain[i] - 'a' + key) % 26) + 'a';
        }
        i++;
    }
    printf("ciphertext: %s\n", plain);
    return 0;
}
