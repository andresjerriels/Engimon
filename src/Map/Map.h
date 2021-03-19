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
};

#endif