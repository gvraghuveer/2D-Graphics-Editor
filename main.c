#include <stdio.h>

#define ROWS 20
#define COLS 50

char canvas[ROWS][COLS];

void initCanvas();
void displayCanvas();
void drawRectangle(int row, int col, int width, int height);

int main()
{
    initCanvas();
    drawRectangle(2, 5, 10, 4);
    displayCanvas();

    return 0;
}

void initCanvas()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void drawRectangle(int row, int col, int width, int height)
{
    int i, j;

    // Top
    for (j = col; j < col + width; j++)
    {
        canvas[row][j] = '*';
    }

    // Bottom
    for (j = col; j < col + width; j++)
    {
        canvas[row + height - 1][j] = '*';
    }

    // Left
    for (i = row; i < row + height; i++)
    {
        canvas[i][col] = '*';
    }

    // Right
    for (i = row; i < row + height; i++)
    {
        canvas[i][col + width - 1] = '*';
    }
}

void displayCanvas()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%c ", canvas[i][j]);
        }
        printf("\n");
    }
}