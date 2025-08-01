#include "gameUI.cpp"

int main() {
	std::vector<NationClasses::Province> provinceMap{};
	gameUI::createMap(&provinceMap);
	std::cout << "Welcome to the nation building simulator!\n";
	gameUI::requestToShowInstructions();
	// Choose a starting province
	NationClasses::Nation playerNation = gameUI::createPlayerNation(&provinceMap);

	bool runGame{ true };
	while (runGame) {
		bool playerTurn{ true };
		playerNation.processResourceGain();
		playerNation.displayNationInfo();

		while (playerTurn) {
			std::string userResponse{};
			bool colonisedThisTurn{ false };

			std::cout << "Please enter the action you would like to take next (type help for a list of instrucitons)\n";
			std::cout << "> ";

			std::cin >> userResponse;
			userResponse = utilities::stringToLower(userResponse);

			if (userResponse == "exit") {
				runGame = false;
				playerTurn = false;
			}
			else if (userResponse == "map" || userResponse == "show map") {
				gameUI::displayMap(provinceMap, playerNation);
			}
			else if (userResponse == "colonise") {
				if (colonisedThisTurn) {
					std::cout << "You can only colonise one province per turn\n";
				}
				else if (playerNation.getGold() >= COLONISECOST) {
					gameUI::coloniseProvince(&provinceMap, &playerNation);
					colonisedThisTurn = true;
				}
				else {
					std::cout << "You do not have enough gold to complete this action (required 5)\n";
				}
			}
			else if (userResponse == "policy" || userResponse == "set policy"){
				playerNation.changeNationPolicy();
			}
			else if (userResponse == "turn" || userResponse == "next turn") {
				playerTurn = false;
			}
			else if (userResponse == "help") {
				gameUI::printHelpInstructions();
			}
			else {
				std::cout << "Command not recognised\n";
			}
		}
		playerNation.updateProvinces();
	}

	return 0;
}

/*
Notes:

Resources:
-Wood
-Metal
-Rare Metals

At some point it will be worth pre-calculating which provinces each province borders (by ocean)
that way we don't have to recaculate every time

*/
