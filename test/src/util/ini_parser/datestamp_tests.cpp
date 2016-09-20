#include "datestamp.h"

#include <gtest/gtest.h>

TEST(Datestamp, Construction)
{
  std::tm tm;
  tm.tm_year = 1991;
  tm.tm_mon = 3;
  tm.tm_mday = 23;

  Ini_Parser::Datestamp date(tm);

  EXPECT_EQ(date.month, 3);
  EXPECT_EQ(date.day_of_month, 23);
  EXPECT_EQ(date.year, 1991);

  Ini_Parser::Datestamp date2(date);

  EXPECT_EQ(date2.month, 3);
  EXPECT_EQ(date2.day_of_month, 23);
  EXPECT_EQ(date2.year, 1991);

  Ini_Parser::Datestamp date3 = date2;

  EXPECT_EQ(date3.month, 3);
  EXPECT_EQ(date3.day_of_month, 23);
  EXPECT_EQ(date3.year, 1991);
}

TEST(Datestamp, Comparison)
{
  std::tm tm;
  tm.tm_year = 1991;
  tm.tm_mon = 3;
  tm.tm_mday = 23;

  Ini_Parser::Datestamp date(tm);

  std::tm tm2;
  tm2.tm_year = 2000;
  tm2.tm_mon = 3;
  tm2.tm_mday = 23;

  Ini_Parser::Datestamp date2(tm2);

  EXPECT_TRUE(date2 > date);
  EXPECT_TRUE(date2 >= date);
  EXPECT_FALSE(date2 == date);
  EXPECT_FALSE(date2 < date);
  EXPECT_FALSE(date2 <= date);
  EXPECT_TRUE(date2 != date);

  std::tm tm3;
  tm3.tm_year = 2000;
  tm3.tm_mon = 3;
  tm3.tm_mday = 23;

  Ini_Parser::Datestamp date3(tm3);

  EXPECT_TRUE(date2 == date3);
  EXPECT_TRUE(date2 >= date3);
  EXPECT_TRUE(date2 <= date3);
  EXPECT_FALSE(date2 != date3);
  EXPECT_FALSE(date2 > date3);
  EXPECT_FALSE(date2 < date3);

  std::tm tm4;
  tm4.tm_year = 2000;
  tm4.tm_mon = 3;
  tm4.tm_mday = 23;

  Ini_Parser::Datestamp date4(tm4);

  std::tm tm5;
  tm5.tm_year = 2000;
  tm5.tm_mon = 3;
  tm5.tm_mday = 24;

  Ini_Parser::Datestamp date5(tm5);

  EXPECT_TRUE(date4 < date5);
  EXPECT_TRUE(date4 <= date5);
  EXPECT_TRUE(date4 != date5);
  EXPECT_FALSE(date4 == date5);
  EXPECT_FALSE(date4 >= date5);
  EXPECT_FALSE(date4 > date5);
}

