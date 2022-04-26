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

TEST(TestPushback, Int){
  mySTL::vector<int> iv;
  iv.push_back(2);
  iv.push_back(10);
  iv.push_back(12);
  EXPECT_EQ(iv[0], 2);
  EXPECT_EQ(iv[1], 10);
  EXPECT_EQ(iv[2], 12);

  // printVector(iv);
}

TEST(TestPushback, String){
  mySTL::vector<string> sv;
  sv.push_back("hi");
  sv.push_back("hello");
  sv.push_back("world");
  EXPECT_EQ(sv[0], "hi");
  EXPECT_EQ(sv[1], "hello");
  EXPECT_EQ(sv[2], "world");
  // printVector(sv);
}



class Vector3{
public:
  Vector3(){
    m_MemoryBlock = new int[5];
  };
  Vector3(float scalar)
    :x(scalar), y(scalar), z(scalar){
      m_MemoryBlock = new int[5];
    };

  Vector3(float _x, float _y, float _z)
    :x(_x), y(_y), z(_z){
      m_MemoryBlock = new int[5];
    };

  Vector3(const Vector3& other) = delete;

  Vector3(Vector3&& other)
    :x(other.x), y(other.y), z(other.z){
      printf("Move\n");
      m_MemoryBlock = other.m_MemoryBlock;
      other.m_MemoryBlock = nullptr;
  }

  ~Vector3(){
    printf("Destory\n");
    delete[] m_MemoryBlock;
  }

  Vector3& operator=(const Vector3& other){
    printf("Copy assignment\n");
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
  }

  Vector3& operator=(Vector3&& other){
    printf("Move assignment\n");  
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os, const Vector3& vec){
    os<<vec.x<<', '<<vec.y<<', '<<vec.z;
    return os;
  }

private:
  float x{};
  float y{};
  float z{};
  int* m_MemoryBlock = nullptr;
};

#if 1
TEST(TestPushback, Class){
  mySTL::vector<Vector3> vec;
  vec.push_back(Vector3());
  vec.push_back(Vector3(1.0f));
  vec.push_back(Vector3(1.0f, 2.0f, 3.0f));
}

TEST(TestEmplaceback, Class){
  mySTL::vector<Vector3> vec;
  vec.emplace_back();
  vec.emplace_back(1.0f);
  vec.emplace_back(1.0f, 2.0f, 3.0f);
}
#endif

TEST(TestPopBack, Class){
  mySTL::vector<Vector3> vec;
  vec.emplace_back();
  vec.emplace_back(1.0f);
  vec.emplace_back(1.0f, 2.0f, 3.0f);
  vec.pop_back();
  vec.pop_back();
}


int main(int argc, char **argv){
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}