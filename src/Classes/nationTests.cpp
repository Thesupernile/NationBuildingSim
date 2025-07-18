#include <gtest/gtest.h>
#include "nation.cpp"

TEST(BasicNationTests, addAndRemoveProvince){
    const int provinceId = 0; // Temp
    const int initPop = 100;

    NationClasses::Nation testNation = NationClasses::Nation("Testopia");
    NationClasses::Province testProvince = NationClasses::Province(initPop, provinceId);

    testNation.addProvince(testProvince);
    EXPECT_EQ(testNation.getAllProvinces().empty(), false);
    
    NationClasses::Province returnedProvince = testNation.removeProvince(provinceId);
    EXPECT_EQ(testProvince.getPop(), returnedProvince.getPop());
    EXPECT_EQ(testNation.getAllProvinces().empty(), true);

    testNation.addProvince(returnedProvince);
    EXPECT_EQ(testNation.getAllProvinces().empty(), false);
}

TEST(BasicNationTests, creditResources){
    const int provinceId = 0; // Temp
    const int initPop = 100;

    const int initGold = 0;
    const int initFood = 0;
    const int finalGold = 1;
    const int finalFood = 1;

    NationClasses::Nation testNation = NationClasses::Nation("Testopia");
    NationClasses::Province testProvince = NationClasses::Province(initPop, provinceId);

    EXPECT_EQ(testNation.getGold(), initGold);
    EXPECT_EQ(testNation.getFood(), initFood);

    // Expect no change as no province to 
    testNation.processResourceGain();
    EXPECT_EQ(testNation.getGold(), initGold);
    EXPECT_EQ(testNation.getFood(), initFood);

    testNation.addProvince(testProvince);
    testNation.processResourceGain();
    EXPECT_EQ(testNation.getGold(), finalGold);
    EXPECT_EQ(testNation.getFood(), finalFood);
}