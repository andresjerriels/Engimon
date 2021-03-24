#ifndef POSITION_H
#define POSITION_H
#include <string>

using namespace std;
class Position{
private:
    int x;
    int y;

public:
    //ctor
    Position();
    Position(int _x, int _y);
    //getter
    int getX() const;
    int getY() const;
    //setter
    void setX(int _x);
    void setY(int _y);
    void setXY(int _x, int _y);
    void setXY(char direction);
    void resetXY(char direction);
};

#endif