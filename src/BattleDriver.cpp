#include "Game.h"

int main(){
    Engimon player = EngimonFactory::createEngimon("Miu", 8);
    Engimon *wild = EngimonFactory::createEngimon(1);
    Battle(player, *wild);
}