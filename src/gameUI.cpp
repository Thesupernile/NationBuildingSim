#include "Classes/nation.cpp"
#include <string>
const int MAPSIZE = 64;

namespace gameUI{
    void createMap(NationClasses::Province provinceMap[]){
        for (int i = 0; i < MAPSIZE; i++){
            provinceMap[i].setId(i);
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