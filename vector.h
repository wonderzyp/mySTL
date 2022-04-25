#pragma once

namespace mySTL{

template <typename T>
class vector{
public:

  vector(){
    reallocate(2);
  }

  ~vector(){}

  void push_back(const T& elem){
    if (m_size >= m_capacity){
      reallocate(m_size<<1);
    }
    m_Data[m_size++] = elem;
  }

  void push_back(T&& elem){
    if (m_size >= m_capacity){
      reallocate(m_size<<1);
    }
    m_Data[m_size++] = elem;
  }

  // 为什么&
  T& operator[](size_t index){return m_Data[index];}


private:
  void reallocate(size_t newCapacity){
    T* newBlock = new T[newCapacity]; //notice

    // 防止下文越界
    if (m_size < newCapacity) m_size = newCapacity;

    // 将旧数据转移至新分配区域
    // 交换
    for (int i=0; i<m_size; ++i){
      newBlock[i] = std::move(m_Data[i]);
    }

    delete[] m_Data;
    m_Data = newBlock;
    m_capacity = newCapacity;
  }



private:
  T* m_Data;
  size_t m_size;
  size_t m_capacity;
};

}// namespace mySTL

