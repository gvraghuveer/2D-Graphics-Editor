#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 50
#define CLEAR_BUFFER() while (getchar() != '\n')

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

void setCanvasPixel(int row, int col)
{
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS)
    {
        canvas[row][col] = '*';
    }
}

// Initiate
void initCanvas();
void displayCanvas();
// Add
void addRectangle(int row, int col, int width, int height);
void addLine(int row1, int col1, int row2, int col2);
void addTriangle(int row1, int col1, int row2, int col2, int row3, int col3);
void addCircle(int centerRow, int centerCol, int radius);
// Draw
void drawRectangle(int row, int col, int width, int height);
void drawLine(int row1, int col1, int row2, int col2);
void drawTriangle(int row1, int col1, int row2, int col2, int row3, int col3);
void drawCircle(int centerRow, int centerCol, int radius);
// Delete
void deleteRectangle(int index);
void deleteLine(int index);
void deleteTriangle(int index);
void deleteCircle(int index);
// Modify
void modifyRectangle(int index, int row, int col, int width, int height);
void modifyLine(int index, int row1, int col1, int row2, int col2);
void modifyTriangle(int index, int row1, int col1, int row2, int col2, int row3, int col3);
void modifyCircle(int index, int centerRow, int centerCol, int radius);
// Render
void renderCanvas();

int main()
{
    int choice;
    int shapeChoice;

    while (1)
    {
        printf("\n===== 2D Graphics Editor =====\n");
        printf("1. Add Object\n");
        printf("2. Delete Object\n");
        printf("3. Modify Object\n");
        printf("4. Display Canvas\n");
        printf("5. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);
        CLEAR_BUFFER();

        switch (choice)
        {
        case 1: // Add
        {
            printf("\n===== Add Object =====\n");
            printf("1. Rectangle\n");
            printf("2. Line\n");
            printf("3. Triangle\n");
            printf("4. Circle\n");

            printf("Enter Choice: ");
            scanf("%d", &shapeChoice);
            CLEAR_BUFFER();

            switch (shapeChoice)
            {
            case 1:
            {
                int row, col, width, height;

                printf("Row: ");
                scanf("%d", &row);
                CLEAR_BUFFER();

                printf("Col: ");
                scanf("%d", &col);
                CLEAR_BUFFER();

                printf("Width: ");
                scanf("%d", &width);
                CLEAR_BUFFER();

                printf("Height: ");
                scanf("%d", &height);
                CLEAR_BUFFER();

                addRectangle(row, col, width, height);
                break;
            }

            case 2:
            {
                int row1, col1, row2, col2;

                printf("Row1: ");
                scanf("%d", &row1);
                CLEAR_BUFFER();

                printf("Col1: ");
                scanf("%d", &col1);
                CLEAR_BUFFER();

                printf("Row2: ");
                scanf("%d", &row2);
                CLEAR_BUFFER();

                printf("Col2: ");
                scanf("%d", &col2);
                CLEAR_BUFFER();

                addLine(row1, col1, row2, col2);
                break;
            }

            case 3:
            {
                int row1, col1;
                int row2, col2;
                int row3, col3;

                printf("Row1: ");
                scanf("%d", &row1);
                CLEAR_BUFFER();

                printf("Col1: ");
                scanf("%d", &col1);
                CLEAR_BUFFER();

                printf("Row2: ");
                scanf("%d", &row2);
                CLEAR_BUFFER();

                printf("Col2: ");
                scanf("%d", &col2);
                CLEAR_BUFFER();

                printf("Row3: ");
                scanf("%d", &row3);
                CLEAR_BUFFER();

                printf("Col3: ");
                scanf("%d", &col3);
                CLEAR_BUFFER();

                addTriangle(
                    row1, col1,
                    row2, col2,
                    row3, col3);

                break;
            }

            case 4:
            {
                int centerRow;
                int centerCol;
                int radius;

                printf("Center Row: ");
                scanf("%d", &centerRow);
                CLEAR_BUFFER();

                printf("Center Col: ");
                scanf("%d", &centerCol);
                CLEAR_BUFFER();

                printf("Radius: ");
                scanf("%d", &radius);
                CLEAR_BUFFER();

                addCircle(
                    centerRow,
                    centerCol,
                    radius);

                break;
            }
            }

            break;
        }

        case 2: // Delete
        {
            printf("\n===== Delete Object =====\n");
            printf("1. Rectangle\n");
            printf("2. Line\n");
            printf("3. Triangle\n");
            printf("4. Circle\n");

            printf("Enter Choice: ");
            scanf("%d", &shapeChoice);
            CLEAR_BUFFER();

            int index;

            printf("Index: ");
            scanf("%d", &index);
            CLEAR_BUFFER();

            switch (shapeChoice)
            {
            case 1:
                deleteRectangle(index);
                break;

            case 2:
                deleteLine(index);
                break;

            case 3:
                deleteTriangle(index);
                break;

            case 4:
                deleteCircle(index);
                break;
            }

            break;
        }

        case 3: // Modify
        {
            printf("\n===== Modify Object =====\n");
            printf("1. Rectangle\n");
            printf("2. Line\n");
            printf("3. Triangle\n");
            printf("4. Circle\n");

            printf("Enter Choice: ");
            scanf("%d", &shapeChoice);
            CLEAR_BUFFER();

            switch (shapeChoice)
            {
            case 1:
            {
                int index;
                int row, col, width, height;

                printf("Rectangle Index: ");
                scanf("%d", &index);
                CLEAR_BUFFER();

                printf("Row: ");
                scanf("%d", &row);
                CLEAR_BUFFER();

                printf("Col: ");
                scanf("%d", &col);
                CLEAR_BUFFER();

                printf("Width: ");
                scanf("%d", &width);
                CLEAR_BUFFER();

                printf("Height: ");
                scanf("%d", &height);
                CLEAR_BUFFER();

                modifyRectangle(
                    index,
                    row,
                    col,
                    width,
                    height);

                break;
            }

            case 2:
            {
                int index;
                int row1, col1, row2, col2;

                printf("Line Index: ");
                scanf("%d", &index);
                CLEAR_BUFFER();

                printf("Row1: ");
                scanf("%d", &row1);
                CLEAR_BUFFER();

                printf("Col1: ");
                scanf("%d", &col1);
                CLEAR_BUFFER();

                printf("Row2: ");
                scanf("%d", &row2);
                CLEAR_BUFFER();

                printf("Col2: ");
                scanf("%d", &col2);
                CLEAR_BUFFER();

                modifyLine(index, row1, col1, row2, col2);

                break;
            }

            case 3:
            {
                int index;
                int row1, col1, row2, col2, row3, col3;

                printf("Triangle Index: ");
                scanf("%d", &index);
                CLEAR_BUFFER();

                printf("Row1: ");
                scanf("%d", &row1);
                CLEAR_BUFFER();

                printf("Col1: ");
                scanf("%d", &col1);
                CLEAR_BUFFER();

                printf("Row2: ");
                scanf("%d", &row2);
                CLEAR_BUFFER();

                printf("Col2: ");
                scanf("%d", &col2);
                CLEAR_BUFFER();

                printf("Row3: ");
                scanf("%d", &row3);
                CLEAR_BUFFER();

                printf("Col3: ");
                scanf("%d", &col3);
                CLEAR_BUFFER();

                modifyTriangle(
                    index,
                    row1, col1,
                    row2, col2,
                    row3, col3);

                break;
            }

            case 4:
            {
                int index;
                int centerRow;
                int centerCol;
                int radius;

                printf("Circle Index: ");
                scanf("%d", &index);
                CLEAR_BUFFER();

                printf("Center Row: ");
                scanf("%d", &centerRow);
                CLEAR_BUFFER();

                printf("Center Col: ");
                scanf("%d", &centerCol);
                CLEAR_BUFFER();

                printf("Radius: ");
                scanf("%d", &radius);
                CLEAR_BUFFER();

                modifyCircle(
                    index,
                    centerRow,
                    centerCol,
                    radius);

                break;
            }
            }

            break;
        }

        case 4:
        {
            renderCanvas();
            displayCanvas();
            printf("\n\nPress Enter to continue...");
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            break;
        }

        case 5:
        {
            printf("Exiting...\n");
            return 0;
        }

        default:
            printf("Invalid Choice!\n");
        }
    }
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
    if (width <= 0 || height <= 0)
    {
        printf("Error: Width and height must be positive\n");
        return;
    }

    if (row < 0 || row >= ROWS || col < 0 || col >= COLS)
    {
        printf("Error: Starting position is outside canvas bounds\n");
        return;
    }

    if (row + height > ROWS || col + width > COLS)
    {
        printf("Error: Rectangle extends beyond canvas bounds\n");
        return;
    }

    rectangles[rectangleCount].row = row;
    rectangles[rectangleCount].col = col;
    rectangles[rectangleCount].width = width;
    rectangles[rectangleCount].height = height;

    rectangleCount++;
}

void addLine(int row1, int col1, int row2, int col2)
{
    // Validate that at least one point is within bounds
    int validStart = (row1 >= 0 && row1 < ROWS && col1 >= 0 && col1 < COLS);
    int validEnd = (row2 >= 0 && row2 < ROWS && col2 >= 0 && col2 < COLS);

    if (!validStart && !validEnd)
    {
        printf("Error: Both endpoints are outside canvas bounds\n");
        return;
    }

    lines[lineCount].row1 = row1;
    lines[lineCount].col1 = col1;
    lines[lineCount].row2 = row2;
    lines[lineCount].col2 = col2;

    lineCount++;
}

void addTriangle(int row1, int col1, int row2, int col2, int row3, int col3)
{
    // Validate that at least one point is within bounds
    int valid1 = (row1 >= 0 && row1 < ROWS && col1 >= 0 && col1 < COLS);
    int valid2 = (row2 >= 0 && row2 < ROWS && col2 >= 0 && col2 < COLS);
    int valid3 = (row3 >= 0 && row3 < ROWS && col3 >= 0 && col3 < COLS);

    if (!valid1 && !valid2 && !valid3)
    {
        printf("Error: All triangle points are outside canvas bounds\n");
        return;
    }

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
    if (radius <= 0)
    {
        printf("Error: Radius must be positive\n");
        return;
    }

    if (centerRow < 0 || centerRow >= ROWS || centerCol < 0 || centerCol >= COLS)
    {
        printf("Error: Center point is outside canvas bounds\n");
        return;
    }

    // Basic bounds check - circle might extend beyond, but we'll let drawCircle handle clipping
    circles[circleCount].centerRow = centerRow;
    circles[circleCount].centerCol = centerCol;
    circles[circleCount].radius = radius;

    circleCount++;
}

void drawRectangle(int row, int col, int width, int height)
{
    int i, j;

    if (width <= 0 || height <= 0)
    {
        return;
    }

    // Top
    for (j = col; j < col + width; j++)
    {
        setCanvasPixel(row, j);
    }

    // Bottom
    for (j = col; j < col + width; j++)
    {
        setCanvasPixel(row + height - 1, j);
    }

    // Left
    for (i = row; i < row + height; i++)
    {
        setCanvasPixel(i, col);
    }

    // Right
    for (i = row; i < row + height; i++)
    {
        setCanvasPixel(i, col + width - 1);
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
            setCanvasPixel(row1, i);
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
            setCanvasPixel(i, col1);
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
            setCanvasPixel((int)(r + 0.5), (int)(c + 0.5));

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
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;

    while (y >= x)
    {
        // Draw all 8 octants
        setCanvasPixel(centerRow + y, centerCol + x);
        setCanvasPixel(centerRow + y, centerCol - x);
        setCanvasPixel(centerRow - y, centerCol + x);
        setCanvasPixel(centerRow - y, centerCol - x);
        setCanvasPixel(centerRow + x, centerCol + y);
        setCanvasPixel(centerRow + x, centerCol - y);
        setCanvasPixel(centerRow - x, centerCol + y);
        setCanvasPixel(centerRow - x, centerCol - y);

        if (d < 0)
        {
            d = d + 4 * x + 6;
        }
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
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

void deleteRectangle(int index)
{
    if (index < 0 || index >= rectangleCount)
    {
        printf("Invalid Rectangle Index\n");
        return;
    }

    for (int i = index; i < rectangleCount - 1; i++)
    {
        rectangles[i] = rectangles[i + 1];
    }

    rectangleCount--;
}

void deleteLine(int index)
{
    if (index < 0 || index >= lineCount)
    {
        printf("Invalid Line Index\n");
        return;
    }

    for (int i = index; i < lineCount - 1; i++)
    {
        lines[i] = lines[i + 1];
    }

    lineCount--;
}

void deleteCircle(int index)
{
    if (index < 0 || index >= circleCount)
    {
        printf("Invalid Circle Index\n");
        return;
    }

    for (int i = index; i < circleCount - 1; i++)
    {
        circles[i] = circles[i + 1];
    }

    circleCount--;
}

void deleteTriangle(int index)
{
    if (index < 0 || index >= triangleCount)
    {
        printf("Invalid Triangle Index\n");
        return;
    }

    for (int i = index; i < triangleCount - 1; i++)
    {
        triangles[i] = triangles[i + 1];
    }

    triangleCount--;
}

void modifyRectangle(int index, int row, int col, int width, int height)
{
    if (index < 0 || index >= rectangleCount)
    {
        printf("Invalid Rectangle Index\n");
        return;
    }

    if (width <= 0 || height <= 0)
    {
        printf("Error: Width and height must be positive\n");
        return;
    }

    if (row < 0 || row >= ROWS || col < 0 || col >= COLS)
    {
        printf("Error: Starting position is outside canvas bounds\n");
        return;
    }

    if (row + height > ROWS || col + width > COLS)
    {
        printf("Error: Rectangle extends beyond canvas bounds\n");
        return;
    }

    rectangles[index].row = row;
    rectangles[index].col = col;
    rectangles[index].width = width;
    rectangles[index].height = height;
}

void modifyLine(int index, int row1, int col1, int row2, int col2)
{
    if (index < 0 || index >= lineCount)
    {
        printf("Invalid Line Index\n");
        return;
    }

    // Validate that at least one point is within bounds
    int validStart = (row1 >= 0 && row1 < ROWS && col1 >= 0 && col1 < COLS);
    int validEnd = (row2 >= 0 && row2 < ROWS && col2 >= 0 && col2 < COLS);

    if (!validStart && !validEnd)
    {
        printf("Error: Both endpoints are outside canvas bounds\n");
        return;
    }

    lines[index].row1 = row1;
    lines[index].col1 = col1;
    lines[index].row2 = row2;
    lines[index].col2 = col2;
}

void modifyTriangle(int index, int row1, int col1, int row2, int col2, int row3, int col3)
{
    if (index < 0 || index >= triangleCount)
    {
        printf("Invalid Triangle Index\n");
        return;
    }

    triangles[index].row1 = row1;
    triangles[index].col1 = col1;

    triangles[index].row2 = row2;
    triangles[index].col2 = col2;

    triangles[index].row3 = row3;
    triangles[index].col3 = col3;
}

void modifyCircle(int index, int centerRow, int centerCol, int radius)
{
    if (index < 0 || index >= circleCount)
    {
        printf("Invalid Circle Index\n");
        return;
    }

    circles[index].centerRow = centerRow;
    circles[index].centerCol = centerCol;
    circles[index].radius = radius;
}