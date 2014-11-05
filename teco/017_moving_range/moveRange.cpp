#include <stdio.h>

#include "moveRange.hpp"

MoveRange::MoveRange(int a_X, int a_Y)
: X(a_X), Y(a_Y)
{
    field = new int*[X];
    vehicle = new int*[X];
    movableRange = new int*[X];
    move = new int*[X];
    for (int i = 0; i < X; ++i) {
        field[i] = new int[Y];
        vehicle[i] = new int[Y];
        movableRange[i] = new int[Y];
        move[i] = new int[Y];
        for (int j = 0; j < Y; ++j) {
            field[i][j] = 0;
            vehicle[i][j] = 0;
            movableRange[i][j] = 0;
            move[i][j] = -1;
        }
    }
}

MoveRange::~MoveRange()
{
    for (int i = 0; i < X; ++i) {
        delete[] field[i];
        delete[] vehicle[i];
        delete[] movableRange[i];
        delete[] move[i];
    }
    delete[] field;
    delete[] vehicle;
    delete[] movableRange;
    delete[] move;
}

bool MoveRange::setFieldFromFile(std::string filePath)
{
    FILE* fp = fopen(filePath.c_str(), "r");
    if (!fp) {
        printf("file not open.\n");
        return false;
    }

    printf("field = \n");
    for (int j = 0; j < Y; ++j) {
        for (int i = 0; i < X; ++i) {
            if (fscanf(fp, "%d,", &field[i][j]) != '\0');
            printf("%d ", field[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    fclose(fp);

    return true;
}

bool MoveRange::setVehicleFromFile(std::string filePath)
{
    FILE* fp = fopen(filePath.c_str(), "r");
    if (!fp) {
        printf("file not open.\n");
        return false;
    }

    printf("vehicle = \n");
    for (int j = 0; j < Y; ++j) {
        for (int i = 0; i < X; ++i) {
            if (fscanf(fp, "%d,", &vehicle[i][j]) != '\0');
            printf("%d ", vehicle[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    fclose(fp);

    return true;
}

void MoveRange::calcMovableRange(int x, int y, int num)
{
    move[x][y] = num;

    for (int n = 0; n < num; ++n) {

        for (int j = 0; j < Y; ++j) {
            for (int i = 0; i < X; ++i) {

                if (move[i][j] > 0) {

                    // up
                    if (canMove(i, j-1)) {
                        move[i][j-1] = std::max(move[i][j] - cost(i, j-1), move[i][j-1]);
                        movableRange[i][j-1] = 1;
                    }
                    // left
                    if (canMove(i-1, j)) {
                        move[i-1][j] = std::max(move[i][j] - cost(i-1, j), move[i-1][j]);
                        movableRange[i-1][j] = 1;
                    }
                    // down
                    if (canMove(i, j+1)) {
                        move[i][j+1] = std::max(move[i][j] - cost(i, j+1), move[i][j+1]);
                        movableRange[i][j+1] = 1;
                    }
                    // right
                    if (canMove(i+1, j)) {
                        move[i+1][j] = std::max(move[i][j] - cost(i+1, j), move[i+1][j]);
                        movableRange[i+1][j] = 1;
                    }

                }

            }
        }

    }


}

void MoveRange::displayMovableRange()
{
    printf("movable range = \n");
    for (int j = 0; j < Y; ++j) {
        for (int i = 0; i < X; ++i) {
            printf("%d ", movableRange[i][j]);
        }
            printf("\n");
    }
    printf("\n");

    printf("move = \n");
    for (int j = 0; j < Y; ++j) {
        for (int i = 0; i < X; ++i) {
            printf("%d ", move[i][j]);
        }
            printf("\n");
    }
}

int MoveRange::cost(int x, int y)
{
    int result = 0;
    if (1 == field[x][y]) {
        result = 1;
    }
    else if (3 == field[x][y]) {
        result = 2;
    }
    return result;
}

bool MoveRange::canMove(int x, int y)
{
    bool result = true;

    if (x < 0 || x >= X || y < 0 || y >= Y ||
        2 == field[x][y] ) {
        result = false;
    }

    return result;
}


