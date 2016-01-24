#include "gtest/gtest.h"
#include "../intx_t.h"
using namespace std;

TEST(intx_t, addition) {
    EXPECT_EQ(254, (intx_t(127) + intx_t(127)).toInt64()) << "Unexpected value in addition of 8 bit positive with 8 bit positive with overflow.";
    EXPECT_EQ(72, (intx_t(32) + intx_t(40)).toInt64()) << "Unexpected value in addition of 8 bit positive with 8 bit positive without overflow.";
    EXPECT_EQ(6148914692668172970, (intx_t(6148914691236517205) + intx_t(1431655765)).toInt64()) << "Unexpected value in addition of 64 bit positive with 32 bit positive.";
    EXPECT_EQ(6148914692668172970, (intx_t(1431655765) + intx_t(6148914691236517205)).toInt64()) << "Unexpected value in addition of 32 bit positive with 64 bit positive.";
    EXPECT_EQ(2147483648, (intx_t(1073741824) + intx_t(1073741824)).toInt64()) << "Unexpected value in addition of 32 bit positive with 32 bit positive with overflow.";
    EXPECT_EQ(3072, (intx_t(1024) + intx_t(2048)).toInt64()) << "Unexpected value in addition of 32 bit positive with 32 bit positive without overflow.";
    EXPECT_EQ(6148914689804861440, (intx_t(-1431655765) + intx_t(6148914691236517205)).toInt64()) << "Unexpected value in addition of 32 bit negative with 64 bit positive.";
    EXPECT_EQ(-6148914689804861440, (intx_t(-6148914691236517205) + intx_t(1431655765)).toInt64()) << "Unexpected value in addition of 64 bit negative with 32 bit positive.";
    EXPECT_EQ(-6148914689804861440, (intx_t(1431655765) + intx_t(-6148914691236517205)).toInt64()) << "Unexpected value in addition of 32 bit positive with 64 bit negative.";
    EXPECT_EQ(6148914689804861440, (intx_t(6148914691236517205) + intx_t(-1431655765)).toInt64()) << "Unexpected value in addition of 64 bit positive with 32 bit negative.";
    EXPECT_EQ("9223372036854775808", (intx_t("4611686018427387904") + intx_t("4611686018427387904")).toString()) <<
        "Unexpected value in addition of 64 bit positive with 64 bit positive.";
    EXPECT_EQ("922337203685477580800", (intx_t("461168601842738790400") + intx_t("461168601842738790400")).toString()) <<
        "Unexpected value in addition of 72 bit positive with 72 bit positive.";
    EXPECT_EQ("170150696844105131245464697992443559544224828046777",
        (intx_t("73167176531330624919225119674426574742355349194934") + intx_t("96983520312774506326239578318016984801869478851843")).toString()) <<
        "Unexpected value in addition of 72 bit positive with 72 bit positive.";
}

TEST(intx_t, subtraction) {

}

TEST(intx_t, multiply) {
    EXPECT_EQ(64, (intx_t(8) * intx_t(8)).toInt64()) << "Unexpected value in multiplication of 8 bit positive by 8 bit positive.";
    EXPECT_EQ(131072, (intx_t(1024) * intx_t(128)).toInt64()) << "Unexpected value in multiplication of 16 bit positive by 8 bit positive.";
    EXPECT_EQ(131072, (intx_t(128) * intx_t(1024)).toInt64()) << "Unexpected value in multiplication of 8 bit positive by 16 bit positive.";
    EXPECT_EQ(16777216, (intx_t(8192) * intx_t(2048)).toInt64()) << "Unexpected value in multiplication of negative 16 bit by positive 16 bit.";
    EXPECT_EQ(-16777216, (intx_t(-8192) * intx_t(2048)).toInt64()) << "Unexpected value in multiplication of negative 16 bit by positive 16 bit.";
    EXPECT_EQ(-16777216, (intx_t(8192) * intx_t(-2048)).toInt64()) << "Unexpected value in multiplication of positive 16 bit by negative 16 bit.";
    EXPECT_EQ("21267647932558653966460912964485513216", (intx_t("4611686018427387904") * intx_t("4611686018427387904")).toString()) << 
        "Unexpected value in mutiplication of 64 bit positive with 64 bit positive.";
    EXPECT_EQ("7096010351354661807337926328530281628100527291536662427785761029903784161894763816757654548712163362", 
        (intx_t("73167176531330624919225119674426574742355349194934") * intx_t("96983520312774506326239578318016984801869478851843")).toString()) <<
        "Unexpected value in mutiplication of 64 bit positive with 64 bit positive.";
}

TEST(intx_t, multiply_one)
{
    intx_t one, two, result;

    for (int i = 1 << 15; i > (1 << 15) - 150;i--)
    {
        one = intx_t(i);
        two = intx_t(i - 10);
        one.multiply_one(two);
    }
}

TEST(intx_t, multiply_two)
{
    intx_t one(325), two(142), result;
    one.multiply_two(two);
    cout << "test: " << one.toString() << endl;

    for (int i = 1 << 15; i > (1 << 15) - 150; i--)
    {
        one = intx_t(i);
        two = intx_t(i - 10);
        one.multiply_two(two);
    }
}

TEST(intx_t, divide) {
    EXPECT_EQ(2, (intx_t(64) / 32).toInt64()) << "Unexpected value in division of 8 bit positive by 8 bit positive.";
    EXPECT_EQ(8, (intx_t(1024) / 128).toInt64()) << "Unexpected value in division of 16 bit positive by 8 bit positive.";
    EXPECT_EQ(0, (intx_t(8) / 9).toInt64()) << "Unexpected value in division of positive 8 bit by positive 8 bit.";
    EXPECT_EQ(-4, (intx_t(-8192) / 2048).toInt64()) << "Unexpected value in division of negative 16 bit by positive 16 bit.";
    EXPECT_EQ(-4, (intx_t(8192) / -2048).toInt64()) << "Unexpected value in division of positive 16 bit by negative 16 bit.";
    EXPECT_EQ(1, intx_t(9) % 8) << "Unexpected modulus value in division of positive 8 bit by positive 8 bit.";
    EXPECT_EQ(1, intx_t(1) % 2) << "Unexpected modulus value in division of positive 8 bit by positive 8 bit.";
    EXPECT_EQ(0, intx_t(4) % 2) << "Unexpected modulus value in division of positive 8 bit by positive 8 bit.";
    EXPECT_THROW(intx_t(1) / 0, std::invalid_argument) << "Expected exepction for divide by zero.";
}

TEST(intx_t, getBit) {
    intx_t test(21845); // 0b 01010101 01010101

    EXPECT_EQ(1, test.getBit(0)) << "Unexpected bit at index 0.";
    EXPECT_EQ(0, test.getBit(1)) << "Unexpected bit at index 1.";
    EXPECT_EQ(0, test.getBit(9)) << "Unexpected bit at index 9.";
    EXPECT_EQ(1, test.getBit(10)) << "Unexpected bit at index 10.";
    EXPECT_EQ(0, test.getBit(15)) << "Unexpected bit at index 15.";
    EXPECT_EQ(0, intx_t(1).getBit(8)) << "Unexpected bit at index out of range.";
    EXPECT_EQ(1, intx_t(-1).getBit(8)) << "Unexpected bit at index out of range.";
}

TEST(intx_t, setBit) {
    intx_t test(0);

    test.setBit(0, 1);
    EXPECT_EQ("00000001", test.toBinaryString()) << "Unexpected value after bit index 0 set.";
    test.setBit(6, 1);
    EXPECT_EQ("01000001", test.toBinaryString()) << "Unexpected value after bit index 6 set.";
    test.setBit(0, 0);
    EXPECT_EQ("01000000", test.toBinaryString()) << "Unexpected value after bit index 0 clear.";
    test.setBit(7, 1);
    EXPECT_EQ("11000000", test.toBinaryString()) << "Unexpceted value after bit index 7 set.";
    test.setBit(14, 1);
    EXPECT_EQ("01000000 11000000", test.toBinaryString()) << "Unexpected value after bit index out of range set.";
}

TEST(intx_t, getHighestBitIndex) {

}

TEST(intx_t, isNegative) {
    EXPECT_EQ(false, intx_t(64).isNegative()) << "Unexpected value of positive 8 bit number.";
    EXPECT_EQ(true, intx_t(-64).isNegative()) << "Unexpected value of negative 8 bit number.";
    EXPECT_EQ(false, intx_t(1024).isNegative()) << "Unexpected value of positive 16 bit number.";
    EXPECT_EQ(true, intx_t(-1024).isNegative()) << "Unexpected value of negative 16 bit number.";
}

TEST(intx_t, setCapacity) {

}

TEST(intx_t, getCapacity) {

}

TEST(intx_t, toString) {
    EXPECT_EQ("74", intx_t(74).toString()) << "Unexpected result of positive 8 bit number.";
    EXPECT_EQ("-74", intx_t(-74).toString()) << "Unexpected result of positive 8 bit number.";
    EXPECT_EQ("3284", intx_t(3284).toString()) << "Unexpected result of positive 16 bit number.";
    EXPECT_EQ("-3284", intx_t(-3284).toString()) << "Unexpected result of positive 16 bit number.";
}

TEST(intx_t, toBinaryString) {
	EXPECT_EQ("01111111 11111111 11111111 11111111 11111111 11111111 11111111 11111111",
	    intx_t(9223372036854775807i64).toBinaryString()) << "Unexpected binary representation of the largest 64 bit number.";

    EXPECT_EQ("10000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000",
        intx_t(-9223372036854775808i64).toBinaryString()) << "Unexpected binary representation of the smallest 64 bit number.";

    EXPECT_EQ("01010101",
        intx_t(85).toBinaryString()) << "Unexpected binary representation of a positive 8 bit number.";

    EXPECT_EQ("10101011",
        intx_t(-85).toBinaryString()) << "Unexpected binary representation of a negative 8 bit number.";
}

TEST(intx_t, fromString) {
    EXPECT_EQ(74, intx_t("74").toInt64()) << "Unexpected value of positive 8 bit number.";
    EXPECT_EQ(-74, intx_t("-74").toInt64()) << "Unexpected value of negative 8 bit number.";
    EXPECT_EQ(3284, intx_t("3284").toInt64()) << "Unexpected value of positive 16 bit number.";
    EXPECT_EQ(-3284, intx_t("-3284").toInt64()) << "Unexpected value of negative 16 bit number.";
    EXPECT_EQ(1465177419, intx_t("1465177419").toInt64()) << "Unexpected value of positive 32 bit number.";
    EXPECT_EQ(-1465177419, intx_t("-1465177419").toInt64()) << "Unexpected value of negative 32 bit number.";
    EXPECT_EQ(6245743553538250357, intx_t("6245743553538250357").toInt64()) << "Unexpected value of positive 64 bit number.";
    EXPECT_EQ(-6245743553538250357, intx_t("-6245743553538250357").toInt64()) << "Unexpected value of negative 64 bit number.";

    EXPECT_THROW(intx_t("7-8"), std::invalid_argument) << "Expected exception with invalid string format.";


}

TEST(intx_t, fromBinaryString) {

    EXPECT_EQ(64, intx_t().fromBinaryString("01000000").toInt64()) << "Unexpected value of positive 8 bit number.";
    EXPECT_EQ(-64, intx_t().fromBinaryString("11000000").toInt64()) << "Unexpected value of negative 8 bit number.";
    EXPECT_EQ(16384, intx_t().fromBinaryString("01000000 00000000").toInt64()) << "Unexpected value of positive 16 bit number.";
    EXPECT_EQ(-16384, intx_t().fromBinaryString("11000000 00000000").toInt64()) << "Unexpected value of negative 16 bit number.";
    EXPECT_EQ(32767, intx_t().fromBinaryString("\t01\r11\r1\n111 \v1\n11\t1\f11\r11").toInt64()) << "Unexpected value of positive 16 bit integer with whitespace.";
    EXPECT_THROW(intx_t().fromBinaryString("01000003"), std::invalid_argument) << "Expected expection for invalid format.";
    EXPECT_THROW(intx_t().fromBinaryString("-01000000"), std::invalid_argument) << "Expected exception for invalid format.";
}

TEST(intx_t, shiftLeft) {
    EXPECT_EQ("00000011 11000000", (intx_t(240) << 2).toBinaryString()) << "Unexpceted value of 8 bit number shifted by 2.";
    EXPECT_EQ("00001100", (intx_t(3) << 2).toBinaryString()) << "Unexpected value of 8 bit number shifted by 2.";
    EXPECT_EQ("00001100 00000000", (intx_t(3) << 10).toBinaryString()) << "Unexpected value of 8 bit number shifted by 10.";
    EXPECT_EQ("00000011", (intx_t(3) << 0).toBinaryString()) << "Unexpected value of 8 bit number shifted by 0.";
}

TEST(intx_t, shiftRight) {
    EXPECT_EQ("00111100", (intx_t(240) >> 2).toBinaryString()) << "Unexpceted value of 8 bit number shifted by 2.";
    EXPECT_EQ("00000000", (intx_t(3) >> 2).toBinaryString()) << "Unexpected value of 8 bit number shifted by 2.";
    EXPECT_EQ("00000011", (intx_t(3) >> 0).toBinaryString()) << "Unexpected value of 8 bit number shifted by 0.";
    EXPECT_EQ("00000000 10000000", (intx_t(256) >> 1).toBinaryString()) << "Unexpected value of 8 bit number shiften by 1.";
}

TEST(intx_t, toInt64) {
    EXPECT_EQ(9223372036854775807, intx_t(9223372036854775807).toInt64()) << "Unexpected value for largest value of 64 bit integer.";
    EXPECT_EQ(-9223372036854775808i64, intx_t(-9223372036854775808i64).toInt64()) << "Unexpected value for smallest value of 64 bit integer.";
    EXPECT_EQ(64, intx_t(64).toInt64()) << "Unexpected value for small number.";
    EXPECT_EQ(1, intx_t(64).getCapacity()) << "Unexpected value for capacity.";
    EXPECT_EQ(-1024, intx_t(-1024).toInt64()) << "Unexpected value for 2 byte negative number.";
    EXPECT_EQ(2, intx_t(-1024).getCapacity()) << "Unexpected value for capacity.";
}

TEST(intx_t, greaterComparison){
    EXPECT_TRUE(intx_t(64) > intx_t(32)) << "Unexpected comparison result of 8 bit > 8 bit.";
    EXPECT_FALSE(intx_t(32) > intx_t(64)) << "Unexpected comparison result of 8 bit > 8 bit.";
    EXPECT_TRUE(intx_t(64) >= intx_t(32)) << "Unexpected comparison result of 8 bit >= 8 bit.";
    EXPECT_FALSE(intx_t(32) >= intx_t(64)) << "Unexpected comparison result of 8 bit >= 8 bit.";
    EXPECT_TRUE(intx_t(32) >= intx_t(32)) << "Unexpected comparison result of 8 bit >= 8 bit.";
    EXPECT_TRUE(intx_t(1024) > intx_t(32)) << "Unexpected comparison result of 16 bit > 8 bit.";
    EXPECT_FALSE(intx_t(32) > intx_t(1024)) << "Unexpected comparison result of 16 bit > 8 bit.";
}

TEST(intx_t, lessComparison) {
    EXPECT_FALSE(intx_t(64) < intx_t(32)) << "Unexpected comparison result of 8 bit < 8 bit.";
    EXPECT_TRUE(intx_t(32) < intx_t(64)) << "Unexpected comparison result of 8 bit < 8 bit.";
    EXPECT_FALSE(intx_t(64) <= intx_t(32)) << "Unexpected comparison result of 8 bit <= 8 bit.";
    EXPECT_TRUE(intx_t(32) <= intx_t(64)) << "Unexpected comparison result of 8 bit <= 8 bit.";
    EXPECT_TRUE(intx_t(32) <= intx_t(32)) << "Unexpected comparison result of 8 bit <= 8 bit.";
    EXPECT_FALSE(intx_t(1024) < intx_t(32)) << "Unexpected comparison result of 16 bit < 8 bit.";
    EXPECT_TRUE(intx_t(32) < intx_t(1024)) << "Unexpected comparison result of 16 bit < 8 bit.";
}

TEST(intx_t, equalityComparison)
{
    EXPECT_TRUE(intx_t(78) == intx_t(78)) << "Unexpected comparison result of 8 bit == 8 bit.";
    EXPECT_FALSE(intx_t(78) == intx_t(64)) << "Unexpected comparison result of 8 bit == 8 bit.";
    EXPECT_FALSE(intx_t(78) != intx_t(78)) << "Unexpected comparison result of 8 bit == 8 bit.";
    EXPECT_TRUE(intx_t(78) != intx_t(64)) << "Unexpected comparison result of 8 bit == 8 bit.";
    EXPECT_FALSE(intx_t(2564) != intx_t(2564)) << "Unexpected comparison result of 16 bit == 16 bit.";
    EXPECT_TRUE(intx_t(2564) != intx_t(3242)) << "Unexpected comparison result of 16 bit == 16 bit.";
    EXPECT_TRUE(intx_t(-2546) == intx_t(-2546)) << "Unexpected comparison result of negative 16 bit == negative 16 bit.";
}