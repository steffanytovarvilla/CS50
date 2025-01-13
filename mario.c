#include <cs50.h>
#include <stdio.h>

int main(void)
{

    // prompt the user for a number for hight from 1 to 8, inclusive.

    int height;
    do
    {
        height = get_int("Height: ");
    }

    while (height < 1 || height > 8);

    // if the number meets the specifications create the pyramid

    // To make each row

    for (int row = 0; row < height; row++)
    {
        for (int spaces = 0; spaces < height - row - 1; spaces++)
        {
            printf(" ");
        }
        // To make each column
        for (int column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n");
    }
}
