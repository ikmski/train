#ifndef _MOVE_RANGE_HPP
#define _MOVE_RANGE_HPP

#include <string>

class MoveRange
{
private:

    int X;
    int Y;
    int** field;
    int** vehicle;
    int** movableRange;

public:

    MoveRange(int a_X, int a_Y);

    ~MoveRange();

    bool setFieldFromFile(std::string filePath);

    bool setVehicleFromFile(std::string filePath);

    void calcMovableRange(int x, int y, int num);

    void displayMovableRange();

private:

    MoveRange(const MoveRange&);
    MoveRange& operator = (const MoveRange&);

};

#endif

