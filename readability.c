#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>

int main(void) {
    float avg = 0;
    int totalWords = 1;
    int totalSentences = 0;
    string text = get_string("Text: ");
    int i = 0;
    while (text[i] != '\0')
    {
        if (text[i] == ' ')
        {
            totalWords++;
        }
        else if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            totalSentences++;
        }
        else if (isalpha(text[i]))
        {
            avg++;
        }
        i++;
    }
    float L = (float)avg / totalWords * 100;
    float S = (float) totalSentences / totalWords * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index <= 16)
    {
        printf("Grade %i\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}
