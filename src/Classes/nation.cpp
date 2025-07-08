#include <vector>
#include "province.cpp"

namespace NationClasses{
    class Nation{
        private:
            std::vector<Province> provinces;
            /*int armyPower;
            int navalPower;
            int airPower;
            int milTechLevel;
            int diploTechLevel;
            int civTechLevel;*/

            //int goldStockpiled;
            /*int foodStockpiled;
            int metalStockpiled;
            int rareMetalStockpiled;
            int woodStockpiled;*/

        public:
            Nation() {

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

                return provinceToRemove;

            }

    };
}