#include <gtest/gtest.h>
#include "StringUtils.h"

TEST(StringUtilsTest, Slice) {
    ASSERT_EQ(StringUtils::Slice("example text", 2, 7), "ample");
    ASSERT_EQ(StringUtils::Slice("example text", -4), "text");
    ASSERT_EQ(StringUtils::Slice("example text", 3, -2), "mple te");
    ASSERT_EQ(StringUtils::Slice("example text", 0, 0), "example text");
}

TEST(StringUtilsTest, Capitalize) {
    ASSERT_EQ(StringUtils::Capitalize("test string"), "Test string");
    ASSERT_EQ(StringUtils::Capitalize("tEST sTRING"), "Test string");
    ASSERT_EQ(StringUtils::Capitalize(""), "");
}

TEST(StringUtilsTest, Upper) {
    ASSERT_EQ(StringUtils::Upper("test string"), "TEST STRING");
    ASSERT_EQ(StringUtils::Upper("tEST sTRING"), "TEST STRING");
    ASSERT_EQ(StringUtils::Upper(""), "");
}

TEST(StringUtilsTest, Lower) {
    ASSERT_EQ(StringUtils::Lower("TEST STRING"), "test string");
    ASSERT_EQ(StringUtils::Lower("tEST sTRING"), "test string");
    ASSERT_EQ(StringUtils::Lower(""), "");
}

TEST(StringUtilsTest, LStrip) {
    ASSERT_EQ(StringUtils::LStrip("   test string"), "test string");
    ASSERT_EQ(StringUtils::LStrip("test string   "), "test string   ");
    ASSERT_EQ(StringUtils::LStrip("   test string   "), "test string   ");
    ASSERT_EQ(StringUtils::LStrip(""), "");
}

TEST(StringUtilsTest, RStrip) {
    ASSERT_EQ(StringUtils::RStrip("test string   "), "test string");
    ASSERT_EQ(StringUtils::RStrip("   test string"), "   test string");
    ASSERT_EQ(StringUtils::RStrip("   test string   "), "   test string");
    ASSERT_EQ(StringUtils::RStrip(""), "");
}

TEST(StringUtilsTest, Strip) {
    ASSERT_EQ(StringUtils::Strip("   test string   "), "test string");
    ASSERT_EQ(StringUtils::Strip("test string"), "test string");
    ASSERT_EQ(StringUtils::Strip("   "), "");
    ASSERT_EQ(StringUtils::Strip(""), "");
}

TEST(StringUtilsTest, Center) {
    ASSERT_EQ(StringUtils::Center("test", 10, '*'), "***test***");
    ASSERT_EQ(StringUtils::Center("test", 4, '-'), "test");
    ASSERT_EQ(StringUtils::Center("test", 8, '_'), "__test__");
}

TEST(StringUtilsTest, LJust) {
    ASSERT_EQ(StringUtils::LJust("test", 10, '*'), "test******");
    ASSERT_EQ(StringUtils::LJust("test", 4, '-'), "test");
    ASSERT_EQ(StringUtils::LJust("test", 6, '_'), "test__");
}

TEST(StringUtilsTest, RJust) {
    // Test padding with asterisks
    ASSERT_EQ(StringUtils::RJust("test", 10, '*'), "******test");
    ASSERT_EQ(StringUtils::RJust("test", 4, '-'), "test"); 
    ASSERT_EQ(StringUtils::RJust("test", 6, '_'), "__test");
    ASSERT_EQ(StringUtils::RJust("", 5, '+'), "+++++");
    ASSERT_EQ(StringUtils::RJust("test", 2, '*'), "test"); 
}

TEST(StringUtilsTest, Replace) {
    ASSERT_EQ(StringUtils::Replace("test string", "string", "example"), "test example");
    ASSERT_EQ(StringUtils::Replace("test string string", "string", "example"), "test example example");
    ASSERT_EQ(StringUtils::Replace("test", "x", "y"), "test");
}

TEST(StringUtilsTest, Split) {
    std::vector<std::string> expected1 = {"test", "string"};
    ASSERT_EQ(StringUtils::Split("test string"), expected1);

    std::vector<std::string> expected2 = {"this", "is", "a", "test"};
    ASSERT_EQ(StringUtils::Split("this is a test"), expected2);

    std::vector<std::string> expected3 = {"test"};
    ASSERT_EQ(StringUtils::Split("test"), expected3);
}

TEST(StringUtilsTest, Join) {
    std::vector<std::string> words = {"test", "string"};
    ASSERT_EQ(StringUtils::Join(" ", words), "test string");
    ASSERT_EQ(StringUtils::Join("-", words), "test-string");
    ASSERT_EQ(StringUtils::Join("", words), "teststring");
}

TEST(StringUtilsTest, ExpandTabs) {
    ASSERT_EQ(StringUtils::ExpandTabs("test\tstring", 4), "test    string");
    ASSERT_EQ(StringUtils::ExpandTabs("\t", 4), "    ");
    ASSERT_EQ(StringUtils::ExpandTabs("test\t", 8), "test    ");
}

TEST(StringUtilsTest, EditDistance) {
    ASSERT_EQ(StringUtils::EditDistance("example", "samples"), 3);
    ASSERT_EQ(StringUtils::EditDistance("test", "text"), 1);
    ASSERT_EQ(StringUtils::EditDistance("same", "same"), 0);
    ASSERT_EQ(StringUtils::EditDistance("test", "TEST", true), 0);
}