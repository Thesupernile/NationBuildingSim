#include <gtest/gtest.h>
#include "province.cpp"

TEST(BasicProvinceTests, setPop){
    NationClasses::Province testProvince = NationClasses::Province(100);
    EXPECT_EQ(testProvince.getPop(), 100);
    testProvince.setPop(1000);
    EXPECT_EQ(testProvince.getPop(), 1000);
}

TEST(BasicProvinceTests, updatePopOnTurnChange){
    NationClasses::Province testProvince = NationClasses::Province(100);
    testProvince.updateProvinceOnTurnChange();
    EXPECT_EQ(testProvince.getPop(), 120);
    testProvince.updateProvinceOnTurnChange();
    EXPECT_EQ(testProvince.getPop(), 144);
}