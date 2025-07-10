#include <vector>
#include "province.cpp"

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

            int goldStockpiled = 0;
            int foodStockpiled = 0;
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
            }

            Province removeProvince(int id){
                int provinceIndex = -1;
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

            void processTurn(){
                int* currentResources[] = {&goldStockpiled, &foodStockpiled};

                for (auto province : provinces){
                    province.creditProvinceResources(currentResources);
                }

                goldStockpiled = *currentResources[0];
                foodStockpiled = *currentResources[1];
            }

            int getGold(){
                return goldStockpiled;
            }

            int getFood(){
                return foodStockpiled;
            }

    };
}