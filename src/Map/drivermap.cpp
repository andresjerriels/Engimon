#include "Map.h"

int main(){
    Map map("../../file/map.txt");
    map.PrintMap();
    return 0;
}

// g++ drivermap.cpp Map.cpp ../Tile/Tile.cpp -o map