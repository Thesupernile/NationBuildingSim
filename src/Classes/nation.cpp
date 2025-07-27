#include "province.cpp"
#include <vector>
const double popPerUnitFood {2000};

namespace NationClasses{
    class Nation{
        private:
            std::vector<Province> provinces;
            std::string nationName;
            /*int armyPower;
            int navalPower;
            int airPower;
            int milTechLevel;
            int diploTechLevel;
            int civTechLevel;*/

            int population = 0;
            resourcesList resources;

            /*int metalStockpiled;
            int rareMetalStockpiled;
            int woodStockpiled;*/

            bool isPlayerControlled = false;

        public:
            Nation(std::string nameInit) {
                nationName = nameInit;
            }

            void addProvince(Province provinceToAdd){
                provinces.push_back(provinceToAdd);
                population += provinceToAdd.getPop();
            }

            Province removeProvince(int id){
                int provinceIndex = -1;
                // Linear search used since list size expected to be small
                for (size_t i = 0; i < provinces.size(); i++){
                    Province currentProvince = provinces[i];
                    if (currentProvince.getId() == id){
                        provinceIndex = i;
                    }
                }
                if (provinceIndex == -1){
                    throw "Province not found";
                }

                Province provinceToRemove = provinces[provinceIndex];
                provinces.erase(provinces.begin() + provinceIndex);

                return provinceToRemove;
            }

            std::vector<Province> getAllProvinces(){
                return provinces;
            }

            void processResourceGain(){
                std::cout << "Playing turn of " << nationName << std::endl;

                for (auto &province : provinces){
                    province.creditProvinceResources(resources);
                }

                std::cout << "Collected resources from provinces.\n";

                // Food must be given to provinces in the amount determined by popPerUnitFood
                resources.foodStockpiled -= population/popPerUnitFood;

                std::cout << "Distributed food to provinces. \n";       
            }

            void updateProvinces(){
                bool isNationStarving {};
                population = 0;

                // If nation is starving, provinces decrease population instead of increasing
                if (resources.foodStockpiled >= 0){
                    isNationStarving = false;
                }
                else{
                    isNationStarving = true;
                    resources.foodStockpiled = 0;
                    std::cout << "You do not have enough food for your people. They are starving.\n";
                }

                // It is necessary to update population here to ensure the pop count is accurate
                for (auto &province : provinces){
                    province.updateProvinceOnTurnChange(isNationStarving);
                    population += province.getPop();
                }
                std::cout << "Provinces updated. \n";
            }

            void displayNationInfo(){
                std::cout.precision(3);

                std::cout << nationName << ": \n\n";
                std::cout << "Total Provinces: " << provinces.size() << "\n";
                std::cout << "Nation Population: " << population << "\n\n";

                std::cout << "Gold: " << resources.goldStockpiled << "\n";
                std::cout << "Food: " << resources.foodStockpiled << "\n";
            }

            double getGold(){
                return resources.goldStockpiled;
            }

            void modifyGold(int value){
                resources.goldStockpiled += value;
            }

            double getFood(){
                return resources.foodStockpiled;
            }

    };
}
