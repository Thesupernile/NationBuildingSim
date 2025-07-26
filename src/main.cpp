#include "gameUI.cpp"

int main(){
    std::vector<NationClasses::Province> provinceMap;
    gameUI::createMap(&provinceMap);
    // Choose a starting province
    NationClasses::Nation playerNation = gameUI::createPlayerNation(&provinceMap);

    bool runGame {true};
    while (runGame){
        bool playerTurn {true};
        playerNation.processResourceGain();
        playerNation.displayNationInfo();

        while (playerTurn){
            std::cout << "Please enter the action you would like to take next (type help for a list of instrucitons)\n";
            std::cout << "> ";
            std::string userResponse;
            std::cin >> userResponse;
            if (userResponse == "exit"){
                runGame = false;
                playerTurn = false;
            }
            else if (userResponse == "map" || userResponse == "show map"){
                gameUI::displayMap(provinceMap, playerNation);
            }
            else if (userResponse == "colonise"){
                if (playerNation.getGold() >= COLONISECOST){
                    gameUI::coloniseProvince(&provinceMap, &playerNation);
                }
                else{
                    std::cout << "You do not have enough gold to complete this action";
                }
            }
            else if (userResponse == "turn" || userResponse == "next turn"){
                playerTurn = false;
            }
            else if (userResponse == "help"){
                gameUI::printHelpInstructions();
            }
            else{
                std::cout << "Command not recognised\n";
            }
        }
        playerNation.updateProvinces();
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
