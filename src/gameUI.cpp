#include "Classes/nation.cpp"
#include <string>
#include <cstdlib>
const int MAPSIZE = 64;

namespace gameUI{
    void createMap(std::vector<NationClasses::Province>* provinceMap){
        for (int i = 0; i < MAPSIZE; i++){
            NationClasses::Province newProvince;
            newProvince.setId(i);
            // Assign province biome at random since it's easier (update in a future version?)
            int randomSelection = rand() % 2;
            switch(randomSelection){
                case 0:
                    newProvince.setIsLand(false);
                    break;
                default:
                    newProvince.setIsLand(true);
                    break;
            }
            (*provinceMap).push_back(newProvince);
        }
    }

    void displayMap(std::vector<NationClasses::Province> provinceMap, NationClasses::Nation playerNation = NationClasses::Nation("null")){
        int mapWidth = floor(sqrt(MAPSIZE));
        int ownedProvincesAdded = 0;

        for(size_t i = 0; i < MAPSIZE; i++){
            if (provinceMap[i - ownedProvincesAdded].getId() == i){
                if(provinceMap[i - ownedProvincesAdded].getIsLand()){
                    std::cout << "#";
                }
                else{
                    std::cout << ".";
                }


                if (i % mapWidth == (mapWidth-1)){
                    std::cout << "\n";
                }
            }
            else{
                ownedProvincesAdded++;
                std::cout << "*";
            }
        }
    }

    void coloniseProvince(std::vector<NationClasses::Province>* provinceMap, NationClasses::Nation* playerNation){
        // Handles colonisation of unowned provinces
        bool validProvinceSelected {false};
        std::string userResponseTemp {};
        int mapWidth = floor(sqrt(MAPSIZE));

        displayMap(*provinceMap, *playerNation);
        std::cout << "Choose a province to select:";
        while (!validProvinceSelected){
            int x {};
            int y {};

            std::cout << "Enter the x-coordinate: \n";
            std::cin >> userResponseTemp;
            x = stoi(userResponseTemp);

            std::cout << "Enter the y-coordinate: \n";
            std::cin >> userResponseTemp;
            y = stoi(userResponseTemp);

            int targetProvinceId = y*mapWidth + x;
            for (int i = 0; i < (*provinceMap).size(); i++){
                if ((*provinceMap)[i].getId() == targetProvinceId){
                    
                    (*playerNation).addProvince((*provinceMap)[i]);
                    (*provinceMap).erase((*provinceMap).begin() + i);

                    (*playerNation).modifyGold(-5);

                    std::cout << "Colonisation successful\n";
                    validProvinceSelected = true;
                }
            }
            if (!validProvinceSelected){
                std::cout << "Province selected already owned\n";
            }
        }
    }

    NationClasses::Nation createPlayerNation(std::vector<NationClasses::Province>* provinceMap){
        NationClasses::Province provinceSelected;
        std::string nationName;
        std::string userResponseTemp;
        int x;
        int y;
        bool validProvinceSelected = false;

        std::cout << "Name your new nation!\n";
        std::cin >> nationName;

        displayMap(*provinceMap);
        std::cout << "Choose a start Position for your nation\n";
        while (!validProvinceSelected){

            std::cout << "Enter the X-Coordinate of the province\n";
            std::cin >> userResponseTemp;
            x = stoi(userResponseTemp);

            std::cout << "Enter the Y-Coordinate of the province\n";
            std::cin >> userResponseTemp;
            y = stoi(userResponseTemp);

            // Map is generated as a square but stored linearly
            int requiredProvinceId = (floor(sqrt(MAPSIZE)) * y) + x;
            // Linear search used since list size is expected to be small
            for(size_t i = 0; i < (*provinceMap).size(); i++){
                if ((*provinceMap)[i].getId() == requiredProvinceId){
                    provinceSelected = (*provinceMap)[i];
                    (*provinceMap).erase((*provinceMap).begin() + i);
                    validProvinceSelected = true;
                    break;
                }
            }
        }

        NationClasses::Nation newNation = NationClasses::Nation(nationName);
        newNation.addProvince(provinceSelected);
        return newNation;
    }
}
