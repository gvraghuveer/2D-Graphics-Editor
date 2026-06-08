#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 50

typedef struct
{
    int row;
    int col;
    int width;
    int height;
} Rectangle;

typedef struct
{
    int row1;
    int col1;
    int row2;
    int col2;
} Line;

typedef struct
{
    int row1;
    int col1;

    int row2;
    int col2;

    int row3;
    int col3;
} Triangle;

typedef struct
{
    int centerRow;
    int centerCol;
    int radius;
} Circle;

Rectangle rectangles[100];
Line lines[100];
Triangle triangles[100];
Circle circles[100];

int rectangleCount = 0;
int lineCount = 0;
int triangleCount = 0;
int circleCount = 0;

char canvas[ROWS][COLS];

void initCanvas();
void displayCanvas();
//Add
void addRectangle(int row, int col, int width, int height);
void addLine(int row1, int col1, int row2, int col2);
void addTriangle(int row1, int col1, int row2, int col2, int row3, int col3);
void addCircle(int centerRow, int centerCol, int radius);
//Draw
void drawRectangle(int row, int col, int width, int height);
void drawLine(int row1, int col1, int row2, int col2);
void drawTriangle(int row1, int col1, int row2, int col2, int row3, int col3);
void drawCircle(int centerRow, int centerCol, int radius);
//Delete
void deleteRectangle(int index);
void deleteLine(int index);
void deleteTriangle(int index);
void deleteCircle(int index);
//Render
void renderCanvas();

int main()
{
    initCanvas();

    addRectangle(2, 5, 10, 4);
    addLine(8, 30, 15, 30);
    addTriangle(10, 5, 15, 5, 15, 15);
    addCircle(15, 40, 5);

    deleteRectangle(0);

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

void addRectangle(int row, int col, int width, int height)
{
    rectangles[rectangleCount].row = row;
    rectangles[rectangleCount].col = col;
    rectangles[rectangleCount].width = width;
    rectangles[rectangleCount].height = height;

    rectangleCount++;
}

void addLine(int row1, int col1, int row2, int col2)
{
    lines[lineCount].row1 = row1;
    lines[lineCount].col1 = col1;
    lines[lineCount].row2 = row2;
    lines[lineCount].col2 = col2;

    lineCount++;
}

void addTriangle(int row1, int col1, int row2, int col2, int row3, int col3)
{
    triangles[triangleCount].row1 = row1;
    triangles[triangleCount].col1 = col1;

    triangles[triangleCount].row2 = row2;
    triangles[triangleCount].col2 = col2;

    triangles[triangleCount].row3 = row3;
    triangles[triangleCount].col3 = col3;

    triangleCount++;
}

void addCircle(int centerRow, int centerCol, int radius)
{
    circles[circleCount].centerRow = centerRow;
    circles[circleCount].centerCol = centerCol;
    circles[circleCount].radius = radius;

    circleCount++;
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

void drawLine(int row1, int col1, int row2, int col2)
{
    int i;
    if (row1 == row2)
    {
        if (col1 > col2)
        {
            int temp = col1;
            col1 = col2;
            col2 = temp;
        }

        for (i = col1; i <= col2; i++)
        {
            canvas[row1][i] = '*';
        }
    }

    else if (col1 == col2)
    {
        if (row1 > row2)
        {
            int temp = row1;
            row1 = row2;
            row2 = temp;
        }

        for (i = row1; i <= row2; i++)
        {
            canvas[i][col1] = '*';
        }
    }

    else
    {
        int dr = row2 - row1;
        int dc = col2 - col1;

        int steps = abs(dr) > abs(dc) ? abs(dr) : abs(dc);

        float rowInc = (float)dr / steps;
        float colInc = (float)dc / steps;

        float r = row1;
        float c = col1;

        for (int i = 0; i <= steps; i++)
        {
            canvas[(int)(r + 0.5)][(int)(c + 0.5)] = '*';

            r += rowInc;
            c += colInc;
        }
    }
}

void drawTriangle(int row1, int col1, int row2, int col2, int row3, int col3)
{
    drawLine(row1, col1, row2, col2);
    drawLine(row2, col2, row3, col3);
    drawLine(row3, col3, row1, col1);
}

void drawCircle(int centerRow, int centerCol, int radius)
{
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            int dx = col - centerCol;
            int dy = row - centerRow;

            int distanceSquared = dx * dx + dy * dy;
            int radiusSquared = radius * radius;

            if (abs(distanceSquared - radiusSquared) <= radius)
            {
                canvas[row][col] = '*';
            }
        }
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

void renderCanvas()
{
    initCanvas();

    for (int i = 0; i < rectangleCount; i++)
    {
        drawRectangle(rectangles[i].row, rectangles[i].col, rectangles[i].width, rectangles[i].height);
    }

    for (int i = 0; i < lineCount; i++)
    {
        drawLine(lines[i].row1, lines[i].col1, lines[i].row2, lines[i].col2);
    }

    for (int i = 0; i < triangleCount; i++)
    {
        drawTriangle(triangles[i].row1, triangles[i].col1, triangles[i].row2, triangles[i].col2, triangles[i].row3, triangles[i].col3);
    }

    for (int i = 0; i < circleCount; i++)
    {
        drawCircle(circles[i].centerRow, circles[i].centerCol, circles[i].radius);
    }
}

void deleteRectangle(int index){
    if(index < 0 || index >= rectangleCount)
    {
        printf("Invalid Rectangle Index\n");
        return;
    }

    for(int i = index; i < rectangleCount - 1; i++)
    {
        rectangles[i] = rectangles[i + 1];
    }

    rectangleCount--;
}