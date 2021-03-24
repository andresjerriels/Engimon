#include "Map.h"

int main(){
    Map map("../../file/map.txt");
    string command;
    do{
        map.PrintMap();
        cin >> command;
        if(command == "w" || command == "a" || command == "s" || command == "d") map.move(command);
    } while (command != "exit");
    return 0;
}

// g++ drivermap.cpp Map.cpp ../Tile/Tile.cpp -o map
// g++ drivermap.cpp Map.cpp DummyTile.cpp Position.cpp -o map