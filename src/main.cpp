#include "gameUI.cpp"

int main(){
    std::vector<NationClasses::Province> provinceMap;
    gameUI::createMap(provinceMap);
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