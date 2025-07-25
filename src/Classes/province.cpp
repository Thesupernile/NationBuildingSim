#include <iostream>
#include "headers/provice.hpp"

namespace NationClasses{
    class Province{
        static int previousId;

        private:
            int id = 0;                     // Id is also used to determine the province's geographical location
            int population;
            double popGrowthFactor = 1.2;
            /*std::string provinceBiome;
            bool containsMetal;
            bool containsRareMetal;*/
            bool containsFood = true;
            bool containsGold = true;
            bool isLand = true;

        public:
            Province (int initPop = 0, int initId = 0, bool isLandInit = false){
                // By default a province is an empty ocean tile
                population = initPop;
                id = initId;
                isLand = isLandInit;
            }

            void updateProvinceOnTurnChange(){
                population = population * popGrowthFactor;
            }

            void creditProvinceResources(double* resourcesList[]){
                double gold = *resourcesList[0];
                double food = *resourcesList[1];

                if (containsGold){
                    gold++;
                }
                if (containsFood){
                    food++;
                }

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
