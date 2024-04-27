
 #include <gtest/gtest.h>
 #include "../src/cpp/Data.cpp"
 #include "../src/cpp/AddUrl.cpp"
 #include "../src/cpp/FindUrl.cpp"
 #include "../src/cpp/FirstMenu.cpp"
 #include "../src/cpp/MenuConsole.cpp"

 #include "../src/header/FirstMenu.h"
 #include "../src/header/MenuConsole.h"
 #include "../src/header/FindUrl.h"
 #include "../src/header/AddUrl.h"
 #include "../src/header/Data.h"

 TEST(DataTest, Constructor)
 {
     std::vector<int> input= {10, 5, 10, 20, 30, 0};
     ASSERT_NO_THROW(Data data(input));
 }

 TEST(DataTest2, Constructor)
 {
     std::vector<int> input = {10, 5, 2, 3, 0, 0};
     Data data(input);

     std::string url = "example.com";
     ASSERT_NO_THROW(data.addUrl(url));
 }

 TEST(DataTest3, Constructor)
 {
     std::vector<int>  input = {10, 5, 2, 3, 0, 0};
     Data data(input);

     std::string url = "example.com";
     data.addUrl(url);

     // Check that the findUrl method returns the correct results
     std::vector<bool>  result = data.findUrl(url);
     EXPECT_TRUE(result[0]);

     // Add more test cases as needed

 }

 // test_firstmenu.cpp

 TEST(FirstMenuTest, GetFirstLine_ValidInput)
 {
     FirstMenu firstMenu = FirstMenu();
     std::istringstream input("10 1 2");
     std::streambuf *originalCin = std::cin.rdbuf(input.rdbuf());

     std::vector<int> dataArr = firstMenu.getFirstLine();

     // Check that the data array is constructed correctly
     EXPECT_EQ(dataArr[0], 10);
     EXPECT_EQ(dataArr[1], 1);
     EXPECT_EQ(dataArr[2], 2);

     // more test
     std::string str = "100 2 2 2 2";

     bool bo = firstMenu.validation(str);

     // Check that the data array is constructed correctly
     EXPECT_TRUE(bo);



     std::cin.rdbuf(originalCin); // Restore original cin buffer
 }

 TEST(FirstMenuTest, GetFirstLine_InvalidInput)
 {
     FirstMenu firstMenu = FirstMenu();

     // Ensure that the function returns nullptr for invalid input
     std::string str2 = "abc 1 3";
     bool bo3 = firstMenu.validation(str2);
     EXPECT_FALSE(bo3);
     // enter valid input

     std::string str1 = "128 1 1 1 1 2";
     bool bo1 = firstMenu.validation(str1);


     // Check that the data array is constructed correctly
     EXPECT_TRUE(bo1);

 }

 TEST(FirstMenuTest, Validation_ValidInput)
 {
     FirstMenu firstMenu = FirstMenu();

     // Valid input should return true
     EXPECT_TRUE(firstMenu.validation("10 1 2"));
     EXPECT_TRUE(firstMenu.validation("100 1 1 1 1 2 2"));
     EXPECT_TRUE(firstMenu.validation("128 1 1 1 1"));
 }

 TEST(FirstMenuTest, Validation_InvalidInput)
 {
     FirstMenu firstMenu = FirstMenu();

     // Invalid input should return false
     EXPECT_FALSE(firstMenu.validation("abc 1 3"));
     EXPECT_FALSE(firstMenu.validation("128 7 3"));
     EXPECT_FALSE(firstMenu.validation("shira"));
     EXPECT_FALSE(firstMenu.validation("a"));
     EXPECT_FALSE(firstMenu.validation("7 8 9"));
 }

 // test_menuconsole.cpp

 TEST(MenuConsoleTest, NextCommand_ValidInput)
 {
     std::istringstream input("1 example.com");
     std::streambuf *originalCin = std::cin.rdbuf(input.rdbuf());

     std::vector<int> inputData= {100, 1, 2};
     Data testData(inputData);
     MenuConsole menu(testData);

     // Check that the nextCommand returns the correct input
     EXPECT_EQ(menu.nextCommand(), "1 example.com");

     std::cin.rdbuf(originalCin); // Restore original cin buffer
 }

 TEST(MenuConsoleTest, Validate_ValidInput)
 {
     // Valid input should return true
     std::vector<int> inputData = {10, 2};
     Data testData(inputData);
     MenuConsole menu(testData);
     EXPECT_TRUE(menu.validate("2 example.com"));
 }

 TEST(MenuConsoleTest, Validate_InvalidInput)
 {
     // Invalid input should return false
     std::vector<int> inputData= {20, 1};
     Data testData(inputData);
     MenuConsole menu(testData);
     EXPECT_FALSE(menu.validate("abc"));
 }

 TEST(MenuConsoleTest, GetCommands)
 {
     std::vector<int> inputData = {127, 1};
     Data testData(inputData);
     MenuConsole menu(testData);

     // Check that the map of commands is initialized correctly
     auto commands = menu.getCommands();
     commands["1"]->execute("example.com");
 }
