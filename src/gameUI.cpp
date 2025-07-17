#include "Classes/nation.cpp"
#include <string>
#include <cstdlib>
const int MAPSIZE = 64;

namespace gameUI{
    void createMap(std::vector<NationClasses::Province> provinceMap){
        for (int i = 0; i < MAPSIZE; i++){
            NationClasses::Province newProvince;
            newProvince.setId(i);
            // Assign province biome at random since it's easier
            int randomSelection = rand() % 2;
            switch(randomSelection){
                case 0:
                    newProvince.setIsLand(false);
                    break;
                default:
                    newProvince.setIsLand(true);
                    break;
            }
            provinceMap.push_back(newProvince);
        }
    }

    void displayMap(std::vector<NationClasses::Province> provinceMap){
        int mapWidth = floor(sqrt(MAPSIZE));
        for(int i = 0; i < provinceMap.size(); i++){
            if(provinceMap[i].getIsLand()){
                std::cout << "#";
            }
            else{
                std::cout << ".";
            }


            if (i % mapWidth == 0){
                std::cout << "\n";
            }
        }
    }

    NationClasses::Nation createPlayerNation(){
        std::string nationName;

        std::cout << "Name your new nation!";
        std::cin >> nationName;

        NationClasses::Nation newNation = NationClasses::Nation(nationName);
        return newNation;
    }
}