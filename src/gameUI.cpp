#include "Classes/nation.cpp"
#include <string>
#include <cstdlib>
const int MAPSIZE = 64;

namespace gameUI{
    void createMap(NationClasses::Province provinceMap[]){
        for (int i = 0; i < MAPSIZE; i++){
            provinceMap[i].setId(i);
            // Assign province biome at random since it's easier
            int randomSelection = rand() % 2;
            switch(randomSelection){
                case 0:
                    provinceMap[i].setLand(false);
                    break;
                default:
                    provinceMap[i].setLand(true);
                    break;
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