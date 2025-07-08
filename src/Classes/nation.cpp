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
                
            }

    };
}