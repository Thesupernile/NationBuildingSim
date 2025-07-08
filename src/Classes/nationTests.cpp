#include <gtest/gtest.h>
#include "nation.cpp"

TEST(BasicNationTests, init){
    NationClasses::Nation testNation = NationClasses::Nation();
    NationClasses::Province testProvince = NationClasses::Province(100);

    testNation.addProvince(testProvince);
    NationClasses::Province returnedProvince = testNation.removeProvince(0);
    EXPECT_EQ(testProvince, returnedProvince);
}