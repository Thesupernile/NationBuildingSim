#include <gtest/gtest.h>
#include "../gameUI.cpp"

TEST(BasicProvinceTests, setPop){
    const int provinceId = 0; // Temp
    const int initPop = 100;
    const int updatedPop = 1000;

    NationClasses::Province testProvince = NationClasses::Province(initPop, provinceId);
    EXPECT_EQ(testProvince.getPop(), initPop);
    testProvince.setPop(updatedPop);
    EXPECT_EQ(testProvince.getPop(), updatedPop);
}

TEST(BasicProvinceTests, updatePopOnTurnChange){
    // Growth rate is default set to 1.2 so it is expected that 100 will produce 120 and 144 when updated twice
    const int provinceId = 0; // Temp
    const int initPop = 100;
    const int expectedPopIter1 = 120;
    const int expectedPopIter2 = 144;

    NationClasses::Province testProvince = NationClasses::Province(initPop, provinceId);
    testProvince.updateProvinceOnTurnChange();
    EXPECT_EQ(testProvince.getPop(), expectedPopIter1);
    testProvince.updateProvinceOnTurnChange();
    EXPECT_EQ(testProvince.getPop(), expectedPopIter2);
}

TEST(MapCreationTest, creatingMap){
    std::vector<NationClasses::Province> provinceMap;
    gameUI::createMap(provinceMap);
}