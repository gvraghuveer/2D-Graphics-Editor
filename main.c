#include <stdio.h>

#define ROWS 20
#define COLS 50


typedef struct{
    int row;
    int col;
    int width;
    int height;
} Rectangle;

typedef struct{
    int row1;
    int col1;
    int row2;
    int col2;
} Line;

Rectangle rectangles[100];
Line lines[100];

int rectangleCount = 0;
int lineCount = 0;
char canvas[ROWS][COLS];

void initCanvas();
void displayCanvas();
void addRectangle(int row, int col, int width, int height);
void addLine(int row1, int col1, int row2, int col2);
void drawRectangle(int row, int col, int width, int height);
void drawLine(int row1, int col1, int row2, int col2);
void renderCanvas();

int main()
{
    initCanvas();

    addRectangle(2, 5, 10, 4);
    addLine(8, 30, 15, 30);

    renderCanvas();
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

void addRectangle(int row, int col, int width, int height){
    rectangles[rectangleCount].row = row;
    rectangles[rectangleCount].col = col;
    rectangles[rectangleCount].width = width;
    rectangles[rectangleCount].height = height;

    rectangleCount++;
}

void addLine(int row1, int col1, int row2, int col2){
    lines[lineCount].row1 = row1;
    lines[lineCount].col1 = col1;
    lines[lineCount].row2 = row2;
    lines[lineCount].col2 = col2;

    lineCount++;
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

void renderCanvas(){
    initCanvas();

    for(int i=0; i<rectangleCount; i++){
        drawRectangle(rectangles[i].row, rectangles[i].col, rectangles[i].width, rectangles[i].height);
    }

    for(int i=0; i<lineCount; i++){
        drawLine(lines[i].row1, lines[i].col1, lines[i].row2, lines[i].col2);
    }
}