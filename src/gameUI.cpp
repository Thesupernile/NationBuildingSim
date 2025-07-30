#include "Classes/nation.cpp"
#include <cstdlib>
const int MAPSIZE{ 64 };                 // Map size. Map is generated as a square
const int COLONISECOST{ 5 };             // Cost to colonise an unowned province

namespace gameUI {
	void createMap(std::vector<NationClasses::Province>* provinceMap) {
		for (int i = 0; i < MAPSIZE; i++) {
			NationClasses::Province newProvince{};
			newProvince.setId(i);
			// Assign province biome at random since it's easier (update in a future version?)
			int randomSelection = rand() % 2;
			switch (randomSelection) {
			case 0:
				newProvince.setIsLand(false);
				break;
			default:
				newProvince.setIsLand(true);
				newProvince.setPop(1000);
				break;
			}
			(*provinceMap).push_back(newProvince);
		}
	}

	void displayMap(std::vector<NationClasses::Province> provinceMap, NationClasses::Nation playerNation = NationClasses::Nation("null")) {
		int mapWidth = floor(sqrt(MAPSIZE));
		int ownedProvincesAdded{ 0 };
		int lineNum { 1 };

		std::cout << "1| ";
		for (size_t i = 0; i < MAPSIZE; i++) {
			if (provinceMap[i - ownedProvincesAdded].getId() == i) {
				if (provinceMap[i - ownedProvincesAdded].getIsLand()) {
					std::cout << "#";
				}
				else {
					std::cout << ".";
				}


				if (i % mapWidth == (mapWidth - 1)) {
					lineNum++;
					std::cout << "\n" << lineNum << "| ";
				}
			}
			else {
				ownedProvincesAdded++;
				std::cout << "*";
			}
		}
		std::cout << "12345678\n";
	}

	void coloniseProvince(std::vector<NationClasses::Province>* provinceMap, NationClasses::Nation* playerNation) {
		// Handles colonisation of unowned provinces
		bool validProvinceSelected{ false };
		std::string userResponseTemp{};
		int mapWidth = floor(sqrt(MAPSIZE));

		displayMap(*provinceMap, *playerNation);
		std::cout << "Choose a province to select:\n";
		while (!validProvinceSelected) {
			int x{};
			int y{};

			// -1 here is necessary to convert from coordinates starting at 1 and coordinates starting at 0
			x = utilities::getIntInput("Enter the X-Coordinate: ", 1, 8) - 1;
			y = utilities::getIntInput("Enter the Y-Coordinate: ", 1, 8) - 1;

			int targetProvinceId = y * mapWidth + x;
			for (int i = 0; i < (*provinceMap).size(); i++) {
				if ((*provinceMap)[i].getId() == targetProvinceId) {
					if ((*provinceMap)[i].getIsLand()){
						(*playerNation).addProvince((*provinceMap)[i]);
						(*provinceMap).erase((*provinceMap).begin() + i);

						(*playerNation).modifyGold(-5);

						std::cout << "Colonisation successful\n";
						validProvinceSelected = true;
					}
					else{
						std::cout << "You cannot colonise ocean provinces.\n";
					}
					break;
				}
			}
			if (!validProvinceSelected){
				std::cout << "Colonisation unsucessfull. Please check to ensure you have correctly inputted the coordinates and try again\n";
			}
		}
	}

	NationClasses::Nation createPlayerNation(std::vector<NationClasses::Province>* provinceMap) {
		NationClasses::Province provinceSelected{};
		std::string nationName{};
		std::string userResponseTemp{};
		int x{};
		int y{};
		bool validProvinceSelected = false;

		std::cout << "To start, name your new nation!\n";
		std::cin >> nationName;

		displayMap(*provinceMap);
		std::cout << "Choose a start Position for your nation\n";
		while (!validProvinceSelected) {

			// -1 here is necessary to convert from coordinates starting at 1 and coordinates starting at 0
			x = utilities::getIntInput("Enter the X-Coordinate: ", 1, 8) - 1;
			y = utilities::getIntInput("Enter the Y-Coordinate: ", 1, 8) - 1;

			// Map is generated as a square but stored linearly
			int requiredProvinceId = (floor(sqrt(MAPSIZE)) * y) + x;
			// Linear search used since list size is expected to be small
			for (size_t i = 0; i < (*provinceMap).size(); i++) {
				if ((*provinceMap)[i].getId() == requiredProvinceId) {
					if ((*provinceMap)[i].getIsLand()){
						provinceSelected = (*provinceMap)[i];
						(*provinceMap).erase((*provinceMap).begin() + i);
						validProvinceSelected = true;
					}
					else{
						std::cout << "You cannot start on an ocean tile";
					}
					break;
				}
			}
		}
		NationClasses::Nation newNation = NationClasses::Nation(nationName);
		newNation.addProvince(provinceSelected);
		return newNation;
	}

	void printHelpInstructions() {
		// Prints instructions of what commands are available for the user
		std::cout << "<---------- Help ---------->\n";
		std::cout << "\nMeta Commands:" << '\n';
		std::cout << "Turn - Moves to the next turn." << '\n';
		std::cout << "Map - Shows the game map." << '\n';
		std::cout << "Help - Shows the help screen (This menu)." << '\n';
		std::cout << "Exit - Exits the program." << '\n';

		std::cout << "\nNation Actions: " << '\n';
		std::cout << "Colonise - Add an unowned province to your nation." << '\n';
		std::cout << "Policy - Change national policy." << '\n';

		std::cout << "\n<----------      ---------->" << std::endl;
	}

	void requestToShowInstructions(){
		std::string userInput {};

		std::cout << "Would you like a brief overview of the instructions? Y/N \n";
		std::cin >> userInput;
		userInput = utilities::stringToLower(userInput);

		if (userInput == "y" || userInput == "yes"){
			std::cout << "<------ Instructions ------>\n\n";
			std::cout << "The goal of the game is to grow your nation as large as possible\n";
			std::cout << "You can do this via policies and colonisation.\n";
			std::cout << "When the game begins, you will be prompted to select a start location.\n";
			std::cout << "To select a location, simply enter the coordinates of that location on the map.\n";
			std::cout << "You cannot settle on ocean tiles (marked with a . on the map).\n";
			std::cout << "You also cannot settle on a province that is already owned (marked with a * on the map).\n";
			std::cout << "The following instructions are possible:\n";
			printHelpInstructions();
			std::cout << "There will the possibility to show these commands later on. So don't worry if you don't remember them all.\n";
			std::cout << "Advice: It's easier to grow in the early game, so get in before your population starts starving.\n";
			std::cout << "Good luck!\n\n";
		}
	}
}
