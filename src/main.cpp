#include "Classes/provice.cpp"
#include <iostream>

bool runTests(){
    int testPop = 100;
    NationClasses::Province testProvince = NationClasses::Province(100);
    if (testProvince.getPop() == testPop){
        return true;
    }
    return false;
}


int main(){
    bool testsPassed = runTests();
    if (testsPassed){ std::cout << "All tests have passed"; }
    else{ std::cout << "Tests Failed"; }
    
    return 0;
}

/*
Notes:

Resources:
-Wood
-Metal
-Rare Metals
-Food
-Gold
-

*/