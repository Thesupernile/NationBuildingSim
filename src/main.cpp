#include "gameUI.cpp"

int main(){
    NationClasses::Province provinceMap[MAPSIZE];
    gameUI::createMap(&provinceMap[MAPSIZE]);
    NationClasses::Nation playerNation = gameUI::createPlayerNation();
    
    return 0;
}

/*
Notes:

Need to implement province initialisation and assignment to inital nations

Resources:
-Wood
-Metal
-Rare Metals
-Food
-Gold
-

*/