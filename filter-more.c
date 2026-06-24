#include "helpers.h"
#include <math.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;
            float avg = ( red + blue + green ) / 3.0;
            image[i][j].rgbtRed = round(avg);
            image[i][j].rgbtGreen = round(avg);
            image[i][j].rgbtBlue = round(avg);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
      for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0;
            int red = 0;
            int blue = 0;
            int green = 0;

            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int  ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        red += copy[ni][nj].rgbtRed;
                        green += copy[ni][nj].rgbtGreen;
                        blue += copy[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }
            image[i][j].rgbtRed = round(red / (float) count);
            image[i][j].rgbtGreen = round(green / (float) count);
            image[i][j].rgbtBlue = round(blue / (float) count);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Gx[3][3] = {{-1, 0, 1},
                    {-2, 0, 2},
                    {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1},
                    {0, 0, 0},
                    {1, 2, 1}};

    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red_x = 0;
            int blue_x = 0;
            int green_x = 0;
            int red_y = 0;
            int blue_y = 0;
            int green_y = 0;

            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int  ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                            red_x += copy[ni][nj].rgbtRed * Gx[di + 1][dj + 1];
                            green_x += copy[ni][nj].rgbtGreen * Gx[di + 1][dj + 1];
                            blue_x += copy[ni][nj].rgbtBlue * Gx[di + 1][dj + 1];

                            red_y += copy[ni][nj].rgbtRed * Gy[di + 1][dj + 1];
                            green_y += copy[ni][nj].rgbtGreen * Gy[di + 1][dj + 1];
                            blue_y += copy[ni][nj].rgbtBlue * Gy[di + 1][dj + 1];
                    }
                }
            }
            image[i][j].rgbtRed = min(255, round(sqrt(red_x * red_x + red_y * red_y)));
            image[i][j].rgbtGreen = min(255, round(sqrt(green_x * green_x + green_y * green_y)));
            image[i][j].rgbtBlue = min(255, round(sqrt(blue_x * blue_x + blue_y * blue_y)));
        }
    }
    return;
}
