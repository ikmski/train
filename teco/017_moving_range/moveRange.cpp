#include <stdio.h>

#include "moveRange.hpp"

MoveRange::MoveRange(int a_X, int a_Y)
: X(a_X), Y(a_Y)
{
    field = new int*[X];
    vehicle = new int*[X];
    movableRange = new int*[X];
    for (int i = 0; i < X; ++i) {
        field[i] = new int[Y];
        vehicle[i] = new int[Y];
        movableRange[i] = new int[Y];
        for (int j = 0; j < Y; ++j) {
            field[i][j] = 0;
            vehicle[i][j] = 0;
            movableRange[i][j] = 0;
        }
    }
}

MoveRange::~MoveRange()
{
    for (int i = 0; i < X; ++i) {
        delete[] field[i];
        delete[] vehicle[i];
        delete[] movableRange[i];
    }
    delete[] field;
    delete[] vehicle;
    delete[] movableRange;
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
}

