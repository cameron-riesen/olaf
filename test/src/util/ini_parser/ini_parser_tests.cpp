#include "ini_parser.h"
#include <fstream>

#include <gtest/gtest.h>

// TEST(Ini_Parser, Exception_Tests)
// {
//   bool got_file_not_found_exception = false;
//   bool got_format_exception = false;
//   bool got_file_not_open_exception = false;

//   try
//   {
//     Ini_Parser parser("does_not_exist.ini");
//     parser.parse_file();
//   }
//   catch (const Ini_Parser::File_Not_Found_Exception  &e)
//   {
//     got_file_not_found_exception = true;
//   }
//   catch (const Ini_Parser::Ini_Format_Exception &e)
//   {
//     got_format_exception = true;
//   }
//   catch (const Ini_Parser::File_Not_Open_Exception &e)
//   {
//     got_file_not_open_exception = true;
//   }

//   EXPECT_TRUE(got_file_not_found_exception);
//   EXPECT_FALSE(got_format_exception);
//   EXPECT_FALSE(got_file_not_open_exception);

//   got_file_not_found_exception = false;
//   got_format_exception = false;
//   got_file_not_open_exception = false;

//   try
//   {
//     Ini_Parser parser;
//     parser.open("does_not_exist.ini");
//     parser.parse_file();
//   }
//   catch (const Ini_Parser::File_Not_Found_Exception  &e)
//   {
//     got_file_not_found_exception = true;
//   }
//   catch (const Ini_Parser::Ini_Format_Exception &e)
//   {
//     got_format_exception = true;
//   }
//   catch (const Ini_Parser::File_Not_Open_Exception &e)
//   {
//     got_file_not_open_exception = true;
//   }

//   EXPECT_TRUE(got_file_not_found_exception);
//   EXPECT_FALSE(got_format_exception);
//   EXPECT_FALSE(got_file_not_open_exception);

//   got_file_not_found_exception = false;
//   got_format_exception = false;
//   got_file_not_open_exception = false;

//   try
//   {
//     Ini_Parser parser;
//     parser.parse_file();
//   }
//   catch (const Ini_Parser::File_Not_Found_Exception  &e)
//   {
//     got_file_not_found_exception = true;
//   }
//   catch (const Ini_Parser::Ini_Format_Exception &e)
//   {
//     got_format_exception = true;
//   }
//   catch (const Ini_Parser::File_Not_Open_Exception &e)
//   {
//     got_file_not_open_exception = true;
//   }

//   EXPECT_FALSE(got_file_not_found_exception);
//   EXPECT_FALSE(got_format_exception);
//   EXPECT_TRUE(got_file_not_open_exception);

//   got_file_not_found_exception = false;
//   got_format_exception = false;
//   got_file_not_open_exception = false;

//   try
//   {
//     Ini_Parser parser("bad_format_1.ini");
//     parser.parse_file();
//   }
//   catch (const Ini_Parser::File_Not_Found_Exception  &e)
//   {
//     got_file_not_found_exception = true;
//   }
//   catch (const Ini_Parser::Ini_Format_Exception &e)
//   {
//     got_format_exception = true;
//   }
//   catch (const Ini_Parser::File_Not_Open_Exception &e)
//   {
//     got_file_not_open_exception = true;
//   }

//   EXPECT_FALSE(got_file_not_found_exception);
//   EXPECT_TRUE(got_format_exception);
//   EXPECT_FALSE(got_file_not_open_exception);

//   got_file_not_found_exception = false;
//   got_format_exception = false;
//   got_file_not_open_exception = false;

//   try
//   {
//     Ini_Parser parser("bad_format_2.ini");
//     parser.parse_file();
//   }
//   catch (const Ini_Parser::File_Not_Found_Exception  &e)
//   {
//     got_file_not_found_exception = true;
//   }
//   catch (const Ini_Parser::Ini_Format_Exception &e)
//   {
//     got_format_exception = true;
//   }
//   catch (const Ini_Parser::File_Not_Open_Exception &e)
//   {
//     got_file_not_open_exception = true;
//   }

//   EXPECT_FALSE(got_file_not_found_exception);
//   EXPECT_TRUE(got_format_exception);
//   EXPECT_FALSE(got_file_not_open_exception);

//   got_file_not_found_exception = false;
//   got_format_exception = false;
//   got_file_not_open_exception = false;

//   try
//   {
//     Ini_Parser parser("bad_format_3.ini");
//     parser.parse_file();
//   }
//   catch (const Ini_Parser::File_Not_Found_Exception  &e)
//   {
//     got_file_not_found_exception = true;
//   }
//   catch (const Ini_Parser::Ini_Format_Exception &e)
//   {
//     got_format_exception = true;
//   }
//   catch (const Ini_Parser::File_Not_Open_Exception &e)
//   {
//     got_file_not_open_exception = true;
//   }

//   EXPECT_FALSE(got_file_not_found_exception);
//   EXPECT_TRUE(got_format_exception);
//   EXPECT_FALSE(got_file_not_open_exception);

//   got_file_not_found_exception = false;
//   got_format_exception = false;
//   got_file_not_open_exception = false;

//   try
//   {
//     Ini_Parser parser("bad_format_4.ini");
//     parser.parse_file();
//   }
//   catch (const Ini_Parser::File_Not_Found_Exception  &e)
//   {
//     got_file_not_found_exception = true;
//   }
//   catch (const Ini_Parser::Ini_Format_Exception &e)
//   {
//     got_format_exception = true;
//   }
//   catch (const Ini_Parser::File_Not_Open_Exception &e)
//   {
//     got_file_not_open_exception = true;
//   }

//   EXPECT_FALSE(got_file_not_found_exception);
//   EXPECT_TRUE(got_format_exception);
//   EXPECT_FALSE(got_file_not_open_exception);
// }


TEST(Ini_Parser, Exception_Tests)
{
  Ini_Parser::Ini_Parser parser("bad_format_1.ini");
  parser.parse_file();
}

