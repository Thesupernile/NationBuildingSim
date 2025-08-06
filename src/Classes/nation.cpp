#include "province.cpp"
#include <vector>
const double popPerUnitFood{ 2000 };

namespace NationClasses {
	class Nation {
	private:
		std::vector<Province> provinces;
		std::string nationName;
		/*struct{
			int armyPower       {0};
			int navalPower      {0};
			int airPower        {0};
			int milTechLevel    {0};
			int diploTechLevel  {0};
			int civTechLevel    {0};
		} nationStats;*/

		resourceModifiersList resourceModifiers {};

		int population{ 0 };
		int daysStarved { 0 };
		resourcesList resources {};

		bool isPlayerControlled = false;
		

	public:
		Nation(std::string nameInit) {
			nationName = nameInit;

			// By default, no multipliers are applied
			resourceModifiers.foodMulti = 1;
			resourceModifiers.goldMulti = 1;
			resourceModifiers.metalMulti = 1;
		}

		void addProvince(Province provinceToAdd) {
			provinces.push_back(provinceToAdd);
			population += provinceToAdd.getPop();
		}

		Province removeProvince(int id) {
			int provinceIndex = -1;
			// Linear search used since list size expected to be small
			for (size_t i = 0; i < provinces.size(); i++) {
				Province currentProvince = provinces[i];
				if (currentProvince.getId() == id) {
					provinceIndex = i;
				}
			}
			if (provinceIndex == -1) {
				throw "Province not found";
			}

			Province provinceToRemove = provinces[provinceIndex];
			provinces.erase(provinces.begin() + provinceIndex);

			return provinceToRemove;
		}

		std::vector<Province> getAllProvinces() {
			return provinces;
		}

		void processResourceGain() {
			std::cout << "Playing turn of " << nationName << std::endl;

			for (auto& province : provinces) {
				province.creditProvinceResources(resources, resourceModifiers);
			}

			std::cout << "Collected resources from provinces.\n";

			// Food must be given to provinces in the amount determined by popPerUnitFood
			resources.foodStockpiled -= population / popPerUnitFood;

			std::cout << "Distributed food to provinces. \n";
		}

		void updateProvinces() {
			bool isNationStarving{};
			population = 0;

			// If nation is starving, provinces decrease population instead of increasing
			if (resources.foodStockpiled >= 0) {
				isNationStarving = false;
			}
			else {
				isNationStarving = true;
				resources.foodStockpiled = 0;
				std::cout << "You do not have enough food for your people. They are starving.\n";
			}

			// It is necessary to update population here to ensure the pop count is accurate
			for (auto& province : provinces) {
				province.updateProvinceOnTurnChange(isNationStarving);
				population += province.getPop();
			}
			std::cout << "Provinces updated. \n";
		}
		
		void changeNationPolicy() {
			std::string userInput {};
			bool validPolicySelected = false;

			while (!validPolicySelected){
				std::cout << "What national policy would you like to take? (type help for a list of possible policies)\n";
				std::cin >> userInput;
				userInput = utilities::stringToLower(userInput);

				if (userInput == "help"){
					displayPossiblePolicies();
				}
				else if (userInput == "gold"){
					resourceModifiers.goldMulti =	1.2;
					resourceModifiers.metalMulti =	0.8;
					resourceModifiers.foodMulti =	0.8;
					validPolicySelected = true;
				}
				else if (userInput == "metal"){
					resourceModifiers.goldMulti =	0.8;
					resourceModifiers.metalMulti = 	1.2;
					resourceModifiers.foodMulti =	0.8;
					validPolicySelected = true;
				}
				else if (userInput == "food"){
					resourceModifiers.goldMulti =	0.8;
					resourceModifiers.metalMulti = 	0.8;
					resourceModifiers.foodMulti =	1.2;
					validPolicySelected = true;
				}
				else if (userInput == "neutral"){
					resourceModifiers.goldMulti = 	1.0;
					resourceModifiers.metalMulti =	1.0;
					resourceModifiers.foodMulti =	1.0;
					validPolicySelected = true;
				}
				else{
					std::cout << "Unknown Command \n";
				}
			}
		}

		void displayPossiblePolicies(){
			std::cout << "Neutral 	- No modifiers\n";
			std::cout << "Food 		- Food gain increased, all other resource gains decreased\n";
			std::cout << "Gold		- Gold gain increased, all other resource gains decreased\n";
			std::cout << "Metal		- Metal gain increased, all other resource gains decreased\n";
		}

		void displayNationInfo() {
			std::cout.precision(2);

			std::cout << nationName << ": \n\n";
			std::cout << "Total Provinces: " << provinces.size() << "\n";
			std::cout << "Nation Population: " << population << "\n\n";

			std::cout << "Gold: " << resources.goldStockpiled << "\n";
			std::cout << "Metal: " << resources.metalStockpiled << "\n";
			std::cout << "Food: " << resources.foodStockpiled << "\n";
		}

		double getGold() {
			return resources.goldStockpiled;
		}

		void modifyGold(int value) {
			resources.goldStockpiled += value;
		}

		double getFood() {
			return resources.foodStockpiled;
		}

	};
}
