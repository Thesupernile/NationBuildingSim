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
            int foodStockpiled;
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
                int* resources[] = {&goldStockpiled, &foodStockpiled};

                for (auto province : provinces){
                    province.creditProvinceResources(resources);
                }

                goldStockpiled = *resources[0];
                foodStockpiled = *resources[1];
            }

    };
}