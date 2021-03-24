#include "Position.h"
Position::Position(){
    x = 0;
    y = 0;
}

Position::Position(int _x, int _y){
    x = _x;
    y = _y;
}

Position::Position(const Position& other){
    x = other.x;
    y = other.y;
}

Position& Position::operator=(const Position& other){
    if(this != &other){
        x = other.x;
        y = other.y;
    }
    return *this;
}

int Position::getX() const{
    return x;
}

int Position::getY() const{
    return y;
}

void Position::setXY(int _x, int _y){
    x = _x;
    y = _y;
}

void Position::setXY(char direction){
    if(direction == 'w'){
        y--;
    } else if (direction == 'a'){
        x--;
    } else if(direction == 's'){
        y++;
    } else if (direction == 'd'){
        x++;
    }
}

void Position::resetXY(char direction){
    if(direction == 'w'){
        y++;
    } else if (direction == 'a'){
        x++;
    } else if(direction == 's'){
        y--;
    } else if (direction == 'd'){
        x--;
    }
}

void Position::setX(int _x){
    x = _x;
}

void Position::setY(int _y){
    y = _y;
}