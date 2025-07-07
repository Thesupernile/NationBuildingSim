#include "headers/provice.hpp"

namespace NationClasses{
    class Province{
        private:
            int population;
            /*std::string provinceBiome;
            bool containsMetal;
            bool containsRareMetal;
            bool containsFood;
            bool containsGold;*/

        public:
            Province (int initPop){
                population = initPop;
            }

            int getPop(){
                return population;
            }
    };
}