#include <gtest/gtest.h>
#include "../vector.h"

#include <iostream>
#include <string>


using namespace std;

// template <typename T>
// void printVector(const mySTL::vector<T>& vec){
//   for (const auto& T x : vec){
//     std::cout<<x<<" ";
//   }
//   std::cout<<std::endl;
// }

TEST(TestPushback, testInt){
  mySTL::vector<int> iv;
  iv.push_back(2);
  iv.push_back(10);
  iv.push_back(12);
  EXPECT_EQ(iv[0], 2);
  EXPECT_EQ(iv[1], 10);
  EXPECT_EQ(iv[2], 12);

  // printVector(iv);
}

TEST(TestPushback, testString){
  mySTL::vector<string> sv;
  sv.push_back("hi");
  sv.push_back("hello");
  sv.push_back("world");
  EXPECT_EQ(sv[0], "hi");
  EXPECT_EQ(sv[1], "hello");
  EXPECT_EQ(sv[2], "world");
  // printVector(sv);
}


int main(int argc, char **argv){
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}