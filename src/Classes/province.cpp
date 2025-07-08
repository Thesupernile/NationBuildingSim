#include "headers/provice.hpp"

namespace NationClasses{
    class Province{
        private:
            int id = 0;
            int population;
            double popGrowthFactor = 1.2;
            /*std::string provinceBiome;
            bool containsMetal;
            bool containsRareMetal;
            bool containsFood;
            bool containsGold;*/

        public:
            Province (int initPop){
                population = initPop;
            }

            void updateProvinceOnTurnChange(){
                population = population * popGrowthFactor;
            }

            int getPop(){
                return population;
            }

            void setPop(int newPop){
                population = newPop;
            }

            int getId(){
                return id;
            }
    };
}