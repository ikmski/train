#include <stdio.h>

#include "moveRange.hpp"

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("arg[1] = inputFileName\n");
        return -1;
    }

    MoveRange* moveRange = new MoveRange(20, 20);

    // 地形入力
    char* tmpFieldFile = argv[1];
    std::string fieldFilePath(tmpFieldFile);
    moveRange->setFieldFromFile(fieldFilePath);

    // 他の機体入力
    if (3 == argc) {
        char* tmpVehicleFile = argv[2];
        std::string vehicleFilePath(tmpVehicleFile);
        moveRange->setVehicleFromFile(vehicleFilePath);
    }

    // 標準入力
    int x;
    int y;
    int move;
    char s[8];

    while (1) {

        printf("Input your vehicle position! ([x],[y],[move])\n");
        scanf("%d,%d,%d",&x, &y, &move);
        printf("x = [%d], y = [%d], move = [%d]\n\n", x, y, move);

        moveRange->calcMovableRange(x, y, move);

        moveRange->displayMovableRange();

        printf("\n");
        printf("Continue ? [y] or [n]\n");
        scanf("%s",s);
        if ('y' == s[0] || 'Y' == s[0]) {
            // continue;
        }
        else {
            break;
        }

    }

    delete moveRange;

    return 0;
}

