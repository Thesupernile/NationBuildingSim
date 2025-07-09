#include <gtest/gtest.h>
#include "nation.cpp"

TEST(BasicNationTests, addAndRemoveProvince){
    NationClasses::Nation testNation = NationClasses::Nation("Testopia");
    NationClasses::Province testProvince = NationClasses::Province(100);

    testNation.addProvince(testProvince);
    EXPECT_EQ(testNation.getAllProvinces().empty(), false);
    
    NationClasses::Province returnedProvince = testNation.removeProvince(0);
    EXPECT_EQ(testProvince.getPop(), returnedProvince.getPop());
    EXPECT_EQ(testNation.getAllProvinces().empty(), true);

    testNation.addProvince(returnedProvince);
    EXPECT_EQ(testNation.getAllProvinces().empty(), false);
}