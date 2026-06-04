#include<stdio.h>

#define ROWS 20
#define COLS 50

char canvas[ROWS][COLS];

void initCanvas();
void displayCanvas();

int main(){
    initCanvas();
    displayCanvas();

    return 0;
}

void initCanvas(){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas(){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            printf("%c ", canvas[i][j]);
        }
    }
}