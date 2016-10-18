#include "ini_parser.h"

#include <gtest/gtest.h>

TEST(Ini_Parser, Get_Values)
{
  Ini_Parser::Ini_Parser parser("test_input/good_file_1.ini");
  parser.parse_file();

  bool value1 = parser.get_as<bool>("tag_1", "value1");
  bool value2 = parser.get_as<bool>("tag_1", "value2");
  int value3 = parser.get_as<int>("tag_1", "value3");
  Ini_Parser::Datestamp value4 = parser.get_as<Ini_Parser::Datestamp>("tag_2", "value4");
  Ini_Parser::Timestamp value5 = parser.get_as<Ini_Parser::Timestamp>("tag_2", "value5");
  float value6 = parser.get_as<float>("tag_3", "value6");
  double value7 = parser.get_as<double>("tag_3", "value7");
  long long value8 = parser.get_as<long long>("tag_4", "value8");

  EXPECT_TRUE(value1);
  EXPECT_FALSE(value2);
  EXPECT_EQ(value3, 34);
  EXPECT_EQ(value4.month, 2);
  EXPECT_EQ(value4.day_of_month, 23);
  EXPECT_EQ(value4.year, 91);
  EXPECT_EQ(value5.hour, 10);
  EXPECT_EQ(value5.minute, 11);
  EXPECT_EQ(value5.second, 12);
  EXPECT_FLOAT_EQ(value6, 34.567);
  EXPECT_DOUBLE_EQ(value7, 342.56749284756);
  EXPECT_EQ(value8, 12345678989743234);
}

TEST(Ini_Parser, File_Exceptions)
{
  bool got_exception = false;
  
  try
  {
    Ini_Parser::Ini_Parser parser("test_input/does_not_exist.ini");
    parser.parse_file();

    bool value1 = parser.get_as<bool>("tag_1", "value1");
    bool value2 = parser.get_as<bool>("tag_1", "value2");
    int value3 = parser.get_as<int>("tag_1", "value3");
    Ini_Parser::Datestamp value4 = parser.get_as<Ini_Parser::Datestamp>("tag_2", "value4");
    Ini_Parser::Timestamp value5 = parser.get_as<Ini_Parser::Timestamp>("tag_2", "value5");
    float value6 = parser.get_as<float>("tag_3", "value6");
    double value7 = parser.get_as<double>("tag_3", "value7");
    long long value8 = parser.get_as<long long>("tag_4", "value8");
  }
  catch (const Ini_Parser::Ini_Parser_Exception  &e)
  {
    got_exception = true;
  }

  EXPECT_TRUE(got_exception);
  
  got_exception = false;

  try
  {
    Ini_Parser::Ini_Parser parser;
    parser.parse_file();

    bool value1 = parser.get_as<bool>("tag_1", "value1");
    bool value2 = parser.get_as<bool>("tag_1", "value2");
    int value3 = parser.get_as<int>("tag_1", "value3");
    Ini_Parser::Datestamp value4 = parser.get_as<Ini_Parser::Datestamp>("tag_2", "value4");
    Ini_Parser::Timestamp value5 = parser.get_as<Ini_Parser::Timestamp>("tag_2", "value5");
    float value6 = parser.get_as<float>("tag_3", "value6");
    double value7 = parser.get_as<double>("tag_3", "value7");
    long long value8 = parser.get_as<long long>("tag_4", "value8");
  }
  catch (const Ini_Parser::Ini_Parser_Exception &e)
  {
    got_exception = true;
  }

  EXPECT_TRUE(got_exception);
}

TEST(Ini_Parser, Format_Exceptions)
{
  bool got_exception = false;

  try
  {
    Ini_Parser::Ini_Parser parser("test_input/bad_format_1.ini");
    parser.parse_file();

    float value1 = parser.get_as<float>("tag_1", "value1");
  }
  catch (const Ini_Parser::Ini_Parser_Exception &e)
  {
    got_exception = true;
  }

  EXPECT_TRUE(got_exception);

  got_exception = false;

  try
  {
    Ini_Parser::Ini_Parser parser("test_input/bad_format_2.ini");
    parser.parse_file();

    float value1 = parser.get_as<float>("tag_1", "value1");
  }
  catch (const Ini_Parser::Ini_Parser_Exception &e)
  {
    got_exception = true;
  }

  EXPECT_TRUE(got_exception);
}

TEST(Ini_Parser, Conversion_Exceptions)
{
  bool got_exception = false;

  try
  {
    Ini_Parser::Ini_Parser parser("test_input/good_file_1.ini");
    parser.parse_file();

    float value1 = parser.get_as<float>("tag_1", "value1");
  }
  catch (const Ini_Parser::Ini_Parser_Exception &e)
  {
    got_exception = true;
  }

  EXPECT_TRUE(got_exception);

  got_exception = false;

  try
  {
    Ini_Parser::Ini_Parser parser("test_input/good_file_1.ini");
    parser.parse_file();

    float value3 = parser.get_as<bool>("tag_1", "value3");
  }
  catch (const Ini_Parser::Ini_Parser_Exception &e)
  {
    got_exception = true;
  }

  EXPECT_TRUE(got_exception);

  got_exception = false;

  try
  {
    Ini_Parser::Ini_Parser parser("test_input/good_file_1.ini");
    parser.parse_file();

    Ini_Parser::Datestamp value3 = parser.get_as<Ini_Parser::Datestamp>("tag_1", "value3");
  }
  catch (const Ini_Parser::Ini_Parser_Exception &e)
  {
    got_exception = true;
  }

  EXPECT_TRUE(got_exception);

  got_exception = false;

  try
  {
    Ini_Parser::Ini_Parser parser("test_input/good_file_1.ini");
    parser.parse_file();

    Ini_Parser::Timestamp value3 = parser.get_as<Ini_Parser::Timestamp>("tag_1", "value3");
  }
  catch (const Ini_Parser::Ini_Parser_Exception &e)
  {
    got_exception = true;
  }

  EXPECT_TRUE(got_exception);

  got_exception = false;

  try
  {
    Ini_Parser::Ini_Parser parser("test_input/good_file_1.ini");
    parser.parse_file();

    long value1 = parser.get_as<long>("tag_1", "value1");
  }
  catch (const Ini_Parser::Ini_Parser_Exception &e)
  {
    got_exception = true;
  }

  EXPECT_TRUE(got_exception);

  got_exception = false;

  try
  {
    Ini_Parser::Ini_Parser parser("test_input/good_file_1.ini");
    parser.parse_file();

    long long value2 = parser.get_as<long long>("tag_1", "value2");
  }
  catch (const Ini_Parser::Ini_Parser_Exception &e)
  {
    got_exception = true;
  }

  EXPECT_TRUE(got_exception);
}

TEST(Ini_Parser, Key_And_Tag_Exceptions)
{
  bool got_exception = false;

  try
  {
    Ini_Parser::Ini_Parser parser("test_input/good_file_1.ini");
    parser.parse_file();

    bool value1 = parser.get_as<bool>("tag_5", "value1");
  }
  catch (const Ini_Parser::Ini_Parser_Exception &e)
  {
    got_exception = true;
  }
  
  EXPECT_TRUE(got_exception);

  got_exception = false;

  try
  {
    Ini_Parser::Ini_Parser parser("test_input/good_file_1.ini");
    parser.parse_file();

    bool value4 = parser.get_as<bool>("tag_1", "value4");
  }
  catch (const Ini_Parser::Ini_Parser_Exception &e)
  {
    got_exception = true;
  }
  
  EXPECT_TRUE(got_exception);
}


