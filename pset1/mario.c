#include <cs50.h>
#include <stdio.h>

// reads input with restrictions
int readInput()
{
    int height;

    // grab user input and checking it
    do
    {
        printf("height: ");
        height = GetInt();

    }while(height < 0 || height > 23);
    return height;
}

// draws a Mario pyramid on-screen
void drawPyramid(int height)
{
    // calc of width
    int width = height + 1;

    for(int i=0, currentHeight = 0; currentHeight < height; currentHeight++)
    {
        // printing white space before block
        for(i = 0; i < (width - (currentHeight + 2)); i++)
        {
            printf(" ");
        }
        // printing blocks
        for(int j = i; j < width - 1; j++)
        {
            printf("#");
        }
        printf("#\n");
    }

}

int main(void)
{
    int height = readInput();

    drawPyramid(height);

    return 0;
}
