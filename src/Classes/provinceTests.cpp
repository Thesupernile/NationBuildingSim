#include <cassert>
#include "province.cpp"

void popStorageTest() {
    // Ensure basic functionality of the population functions
    // Test for init of pop
    int testPop = 100;
    NationClasses::Province testProvince = NationClasses::Province(100);
    assert(testProvince.getPop() == testPop);

    // Test for updating pop
    testPop = 1000;
    testProvince.setPop(testPop);
    assert(testProvince.getPop() == testPop);
}

int main(){
    popStorageTest();
    return 0;
}