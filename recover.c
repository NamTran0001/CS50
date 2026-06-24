#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./recover File\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    uint8_t buffer[512];
    int count = 0;
    FILE *img = NULL;
    char filename[8];
    while(fread(buffer, 1, 512, card) == 512)
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 &&
            buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                if (img != NULL)
                {
                    fclose(img);
                }
                sprintf(filename, "%03i.jpg", count);
                img = fopen(filename, "w");
                count++;
            }
        if (img != NULL)
            {
                fwrite(buffer, 1, 512, img);
            }
    }
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(card);
}
