#include <iostream>
#include "headers/provice.hpp"

const double popStarveFactor = 0.8;

namespace NationClasses{
    class Province{
        static int previousId;

        private:
            int id = 0;                     // Id is also used to determine the province's geographical location
            int daysStarved = 0;
            int population;
            double popGrowthFactor = 1.2;
            /*std::string provinceBiome;
            bool containsMetal;
            bool containsRareMetal;*/
            int farmLevel = 1;
            bool containsGold = true;
            bool isLand = true;

        public:
            Province (int initPop = 0, int initId = 0, bool isLandInit = false){
                // By default a province is an empty ocean tile
                population = initPop;
                id = initId;
                isLand = isLandInit;
            }

            void updateProvinceOnTurnChange(bool isProvinceStarving){
                if (isProvinceStarving){
                    population = population * pow(popStarveFactor, daysStarved);
                    daysStarved++;
                }
                else{
                    population = population * popGrowthFactor;
                    daysStarved = 0;
                }
            }

            void creditProvinceResources(double* resourcesList[]){
                double gold = *resourcesList[0];
                double food = *resourcesList[1];

                if (containsGold){
                    gold++;
                }
                
                food += farmLevel;

                *resourcesList[0] = gold;
                *resourcesList[1] = food;
            }

            // Getters and Setters

            int getPop(){
                return population;
            }

            void setPop(int newPop){
                population = newPop;
            }

            int getId(){
                return id;
            }

            void setId(int newId){
                id = newId;
            }

            void setIsLand(bool isLandNewValue){
                isLand = isLandNewValue;
            }

            bool getIsLand(){
                return isLand;
            }
    };
}
