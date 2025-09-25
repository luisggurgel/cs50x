#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            float newpixel = round(round(red + green + blue) / 3);

            image[i][j].rgbtRed = newpixel;
            image[i][j].rgbtGreen = newpixel;
            image[i][j].rgbtBlue = newpixel;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            float sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            float sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
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
           int red = image[i][width - j - 1].rgbtRed;
           int green = image[i][width - j - 1].rgbtGreen;
           int blue = image[i][width - j - 1].rgbtBlue;
           image[i][width - j - 1].rgbtRed = image[i][j].rgbtRed;
           image[i][width - j - 1].rgbtGreen = image[i][j].rgbtGreen;
           image[i][width - j - 1].rgbtBlue = image[i][j].rgbtBlue;

           image[i][j].rgbtRed = red;
           image[i][j].rgbtGreen = green;
           image[i][j].rgbtBlue = blue;
       }
   }
   return;
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE oldimage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            oldimage[i][j].rgbtRed = image[i][j].rgbtRed;
            oldimage[i][j].rgbtGreen = image[i][j].rgbtGreen;
            oldimage[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0;
            int redsum = 0;
            int greensum = 0;
            int bluesum = 0;
            float redaverage = 0;
            float greenaverage = 0;
            float blueaverage = 0;

            if (i - 1 >= 0 && i - 1 < height && j - 1 >= 0 && j - 1 < height)
            {
                redsum += oldimage[i - 1][j - 1].rgbtRed;
                greensum += oldimage[i - 1][j - 1].rgbtGreen;
                bluesum += oldimage[i - 1][j - 1].rgbtBlue;
                count++;
            }
            if (i >= 0 && i < height && j >= 0 && j < height)
            {
                redsum += oldimage[i][j].rgbtRed;
                greensum += oldimage[i][j].rgbtGreen;
                bluesum += oldimage[i][j].rgbtBlue;
                count++;
            }
            if (i + 1 >= 0 && i + 1 < height && j + 1 >= 0 && j + 1 < height)
            {
                redsum += oldimage[i + 1][j + 1].rgbtRed;
                greensum += oldimage[i + 1][j + 1].rgbtGreen;
                bluesum += oldimage[i + 1][j + 1].rgbtBlue;
                count++;
            }
            if (i >= 0 && i < height && j - 1 >= 0 && j - 1 < height)
            {
                redsum += oldimage[i][j - 1].rgbtRed;
                greensum += oldimage[i][j - 1].rgbtGreen;
                bluesum += oldimage[i][j - 1].rgbtBlue;
                count++;
            }
            if (i >= 0 && i < height && j + 1 >= 0 && j + 1 < height)
            {
                redsum += oldimage[i][j + 1].rgbtRed;
                greensum += oldimage[i][j + 1].rgbtGreen;
                bluesum += oldimage[i][j + 1].rgbtBlue;
                count++;
            }
            if (i - 1 >= 0 && i - 1 < height && j >= 0 && j < height)
            {
                redsum += oldimage[i - 1][j].rgbtRed;
                greensum += oldimage[i - 1][j].rgbtGreen;
                bluesum += oldimage[i - 1][j].rgbtBlue;
                count++;
            }
            if (i + 1 >= 0 && i + 1 < height && j >= 0 && j < height)
            {
                redsum += oldimage[i + 1][j].rgbtRed;
                greensum += oldimage[i + 1][j].rgbtGreen;
                bluesum += oldimage[i + 1][j].rgbtBlue;
                count++;
            }
            if (i - 1 >= 0 && i - 1 < height && j + 1 >= 0 && j + 1 < height)
            {
                redsum += oldimage[i - 1][j + 1].rgbtRed;
                greensum += oldimage[i - 1][j + 1].rgbtGreen;
                bluesum += oldimage[i - 1][j + 1].rgbtBlue;
                count++;
            }
            if (i + 1 >= 0 && i + 1 < height && j - 1 >= 0 && j - 1 < height)
            {
                redsum += oldimage[i + 1][j - 1].rgbtRed;
                greensum += oldimage[i + 1][j - 1].rgbtGreen;
                bluesum += oldimage[i + 1][j - 1].rgbtBlue;
                count++;
            }
            redaverage = (float) redsum / count;
            greenaverage = (float) greensum / count;
            blueaverage = (float) bluesum / count;

            image[i][j].rgbtRed = round(redaverage);
            image[i][j].rgbtGreen = round(greenaverage);
            image[i][j].rgbtBlue = round(blueaverage);
        }
    }
    return;
}
