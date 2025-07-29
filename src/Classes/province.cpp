#include <iostream>
#include "headers/provice.hpp"

const double popStarveFactor{ 0.95 };

namespace NationClasses {
	class Province {
		static int previousId;

	private:
		int id{ 0 };                     // Id is also used to determine the province's geographical location
		int daysStarved{ 0 };
		int population;
		double popGrowthFactor{ 1.02 };
		/*std::string provinceBiome;
		bool containsMetal;
		bool containsRareMetal;*/
		int farmLevel{ 1 };
		bool containsGold{ true };
		bool isLand{ true };

	public:
		Province(int initPop = 0, int initId = 0, bool isLandInit = false) {
			// By default a province is an empty ocean tile
			population = initPop;
			id = initId;
			isLand = isLandInit;
		}

		void updateProvinceOnTurnChange(bool isProvinceStarving) {
			if (isProvinceStarving) {
				population = population * pow(popStarveFactor, daysStarved);
				daysStarved++;
			}
			else {
				population = population * popGrowthFactor;
				daysStarved = 0;
			}
		}

		void creditProvinceResources(resourcesList& currentResources, resourceModifiersList& resourceModifiers) {
			if (containsGold) {
				currentResources.goldStockpiled += (1 * resourceModifiers.goldMulti);
			}

			currentResources.foodStockpiled += farmLevel * resourceModifiers.foodMulti;
		}

		// Getters and Setters

		int getPop() {
			return population;
		}

		void setPop(int newPop) {
			population = newPop;
		}

		int getId() {
			return id;
		}

		void setId(int newId) {
			id = newId;
		}

		void setIsLand(bool isLandNewValue) {
			isLand = isLandNewValue;
		}

		bool getIsLand() {
			return isLand;
		}
	};
}
