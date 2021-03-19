#include "FireEngimon.h"

FireEngimon::FireEngimon(std::string name) : Engimon(name, fire) {
    this->species = "ApiMon";
    this->slogan = "Ada engimon api";
}