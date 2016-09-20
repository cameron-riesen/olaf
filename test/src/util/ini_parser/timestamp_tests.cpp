#include "timestamp.h"

#include <gtest/gtest.h>

TEST(Timestamp, Construction)
{
  std::tm tm;
  tm.tm_hour = 11;
  tm.tm_min = 45;
  tm.tm_sec = 12;

  Ini_Parser::Timestamp time(tm);

  EXPECT_EQ(time.hour, 11);
  EXPECT_EQ(time.minute, 45);
  EXPECT_EQ(time.second, 12);

  Ini_Parser::Timestamp time2(time);

  EXPECT_EQ(time2.hour, 11);
  EXPECT_EQ(time2.minute, 45);
  EXPECT_EQ(time2.second, 12);

  Ini_Parser::Timestamp time3 = time2;

  EXPECT_EQ(time3.hour, 11);
  EXPECT_EQ(time3.minute, 45);
  EXPECT_EQ(time3.second, 12);
}

TEST(Timestamp, Comparison)
{
  std::tm tm;
  tm.tm_hour = 7;
  tm.tm_min = 24;
  tm.tm_sec = 48;

  Ini_Parser::Timestamp time(tm);
  
  std::tm tm2;
  tm2.tm_hour = 9;
  tm2.tm_min = 10;
  tm2.tm_sec = 58;

  Ini_Parser::Timestamp time2(tm2);

  EXPECT_TRUE(time2 != time);
  EXPECT_TRUE(time2 > time);
  EXPECT_TRUE(time2 >= time);
  EXPECT_FALSE(time2 <= time);
  EXPECT_FALSE(time2 < time);
  EXPECT_FALSE(time2 == time);

  Ini_Parser::Timestamp time3(time2);

  EXPECT_TRUE(time2 == time3);
  EXPECT_TRUE(time2 >= time3);
  EXPECT_TRUE(time2 <= time3);
  EXPECT_FALSE(time2 != time3);
  EXPECT_FALSE(time2 > time3);
  EXPECT_FALSE(time2 < time3);

  std::tm tm4;
  tm4.tm_hour = 20;
  tm4.tm_min = 10;
  tm4.tm_sec = 58;

  Ini_Parser::Timestamp time4(tm4);

  EXPECT_TRUE(time3 <= time4);
  EXPECT_TRUE(time3 < time4);
  EXPECT_TRUE(time3 != time4);
  EXPECT_FALSE(time3 >= time4);
  EXPECT_FALSE(time3 > time4);
  EXPECT_FALSE(time3 == time4);
}
