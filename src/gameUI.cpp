#include "Classes/nation.cpp"
#include <string>

namespace gameUI{
    NationClasses::Nation createPlayerNation(){
        std::string nationName;

        std::cout << "Name your new nation!";
        std::cin >> nationName;

        NationClasses::Nation newNation = NationClasses::Nation(nationName);
        return newNation;
    }
}