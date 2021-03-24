#include "Map.h"

int main(){
    Map map("../../file/map.txt");
    string command;
    do{
        map.PrintMap();
        cin >> command;
        if(command == "w" || command == "a" || command == "s" || command == "d"){
            try{
                map.move(command);
            }catch(const char* err){
                cout << err;
            }
        }
        else if (command == "clc") map.changeLevelCapslock();
    } while (command != "exit");
    printf("\033[0m");
    return 0;
}
