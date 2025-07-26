#include "province.cpp"
#include <vector>
const double popPerUnitFood = 2000;

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
            double goldStockpiled = 0;
            double foodStockpiled = 0;
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
                double* currentResources[] = {&goldStockpiled, &foodStockpiled};

                for (auto &province : provinces){
                    province.creditProvinceResources(currentResources);
                }

                goldStockpiled = *currentResources[0];
                foodStockpiled = *currentResources[1];

                std::cout << "Collected resources from provinces.\n";

                // Food must be given to provinces in the amount determined by popPerUnitFood
                foodStockpiled -= population/popPerUnitFood;

                std::cout << "Distributed food to provinces. \n";       
            }

            void updateProvinces(){
                // It is necessary to update population here to ensure the pop count is accurate
                population = 0;
                for (auto &province : provinces){
                    province.updateProvinceOnTurnChange();
                    population += province.getPop();
                }
                std::cout << "Provinces updated. \n";
            }

            void displayNationInfo(){
                std::cout.precision(3);

                std::cout << nationName << ": \n\n";
                std::cout << "Total Provinces: " << provinces.size() << "\n";
                std::cout << "Nation Population: " << population << "\n\n";

                std::cout << "Gold: " << goldStockpiled << "\n";
                std::cout << "Food: " << foodStockpiled << "\n";
            }

            double getGold(){
                return goldStockpiled;
            }

            void modifyGold(int value){
                goldStockpiled += value;
            }

            double getFood(){
                return foodStockpiled;
            }

    };
}
