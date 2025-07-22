#include "gameUI.cpp"

int main(){
    std::vector<NationClasses::Province> provinceMap;
    gameUI::createMap(&provinceMap);
    // Choose a starting province
    NationClasses::Nation playerNation = gameUI::createPlayerNation(&provinceMap);

    bool runGame = true;
    while (runGame){
        playerNation.processResourceGain();
        playerNation.displayNationInfo();

        std::cout << "Would you like to continue? Y/N\n";
        std::string userResponse;
        std::cin >> userResponse;
        if (userResponse == "N"){
            runGame = false;
        }
    }
    
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

At some point it will be worth pre-calculating which provinces each province borders (by ocean) 
that way we don't have to recaculate every time

*/