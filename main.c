#include <stdio.h>

#define ROWS 20
#define COLS 50

char canvas[ROWS][COLS];

void initCanvas();
void displayCanvas();
void drawRectangle(int row, int col, int width, int height);
void drawLine(int row1, int col1, int row2, int col2);

int main()
{
    initCanvas();
    drawRectangle(2, 5, 10, 4);
    drawLine(8, 30, 15, 30);
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

void drawLine(int row1, int col1, int row2, int col2){
    int i;
    if(row1 == row2){
        if(col1 > col2){
            int temp = col1;
            col1 = col2;
            col2 = temp;
        }

        for(i=col1; i<=col2; i++){
            canvas[row1][i] = '*';
        }
    }

    else if(col1 == col2){
        if(row1 > row2){
            int temp = row1;
            row1 = row2;
            row2 = temp;
        }

        for(i=row1; i<=row2; i++){
            canvas[i][col1] = '*';
        }
    }

    else{
        printf("Horizontal and Vertical are accepted.");
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