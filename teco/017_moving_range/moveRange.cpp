#include <stdio.h>

#include "moveRange.hpp"

const int FIELD_GRASS = 1;
const int FIELD_ROCK  = 2;
const int FIELD_WATER = 3;

const int COST_GRASS = 1;
const int COST_WATER = 2;

const int VEHICLE_ENEMY  = 1;
const int VEHICLE_FRIEND = 2;

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
            printf(" %d", field[i][j]);
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
            printf(" %d", vehicle[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    fclose(fp);

    return true;
}

void MoveRange::calcMovableRange(int x, int y, int num)
{
    init();

    move[x][y] = num;

    for (int n = 0; n < num; ++n) {

        for (int j = 0; j < Y; ++j) {
            for (int i = 0; i < X; ++i) {

                if (move[i][j] > 0) {

                    // up
                    if (canMove(i, j-1)) {
                        move[i][j-1] = std::max(move[i][j] - cost(i, j-1), move[i][j-1]);
                        movableRange[i][j-1] = (int)canStop(i, j-1);
                    }
                    // left
                    if (canMove(i-1, j)) {
                        move[i-1][j] = std::max(move[i][j] - cost(i-1, j), move[i-1][j]);
                        movableRange[i-1][j] = (int)canStop(i-1, j);
                    }
                    // down
                    if (canMove(i, j+1)) {
                        move[i][j+1] = std::max(move[i][j] - cost(i, j+1), move[i][j+1]);
                        movableRange[i][j+1] = (int)canStop(i, j+1);
                    }
                    // right
                    if (canMove(i+1, j)) {
                        move[i+1][j] = std::max(move[i][j] - cost(i+1, j), move[i+1][j]);
                        movableRange[i+1][j] = (int)canStop(i+1, j);
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
            printf(" %d", movableRange[i][j]);
        }
            printf("\n");
    }
    printf("\n");

    /*
    printf("move = \n");
    for (int j = 0; j < Y; ++j) {
        for (int i = 0; i < X; ++i) {
            printf(" %d", move[i][j]);
        }
            printf("\n");
    }
    */
}

void MoveRange::init()
{
    for (int i = 0; i < X; ++i) {
        for (int j = 0; j < Y; ++j) {
            movableRange[i][j] = 0;
            move[i][j] = -1;
        }
    }
}

int MoveRange::cost(int x, int y)
{
    int result = 0;
    if (FIELD_GRASS == field[x][y]) {
        result = COST_GRASS;
    }
    else if (FIELD_WATER == field[x][y]) {
        result = COST_WATER;
    }
    return result;
}

bool MoveRange::canMove(int x, int y)
{
    bool result = true;

    if (x < 0 || x >= X || y < 0 || y >= Y ||
        FIELD_ROCK == field[x][y] ||
        VEHICLE_ENEMY == vehicle[x][y]) {
        result = false;
    }

    return result;
}

bool MoveRange::canStop(int x, int y)
{
    bool result = true;
    if (VEHICLE_FRIEND == vehicle[x][y]) {
        result = false;
    }
    return result;
}

