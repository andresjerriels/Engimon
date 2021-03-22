#ifndef MAP_H
#define MAP_H
#include "../Tile/Tile.h"
#include <bits/stdc++.h> //ini ntar diubah mager soalnya tadi
using namespace std;

class Map
{
private:
    vector<vector<Tile>> mapMatrix;
    int width;
    int length;
    int nWildEngimon;
    Position playerPosition;
    static map<char, Position*> moveMap;

public:
    //ctor
    Map(string);
    //dtor
    ~Map();
    //cctor
    Map(const Map&);
    //assignment operator
    Map& operator= (const Map&);
    //method untuk mencetak peta
    void PrintMap();
    //method untuk generate wild engimon
    void GenerateEngimon();
    //cek posisi player
    bool isPlayerPosition(int x, int y);
    //move player
    void move(char direction);
};

class Position{
private:
    int x;
    int y;

public:
    //ctor
    Position();
    Position::Position(int _x, int _y);
    //getter
    int getX();
    int getY();
    //setter
    void setX(int _x);
    void setY(int _y);
    //overload operator + dan -
    Position operator+(Position& const other);
    Position operator-(Position& const other);
};

#endif