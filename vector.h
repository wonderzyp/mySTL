#pragma once

namespace mySTL{

template <typename T>
class vector{
public:

  vector(){realloc(2);}
  
  void push_back(const T& value){
    if (m_size >= m_capacity) 
      realloc(m_size<<1);
    
    m_Data[m_size++] = value;
  }

  T& operator[](size_t index) {return m_Data[index];}
  const T& operator[](size_t index) const {return m_Data[index];}

  size_t size(){return m_size;}

private:
  void realloc(size_t newCapacity){
    T* newBlock = new T[newCapacity];

    if (newCapacity < m_size)
      m_size = newCapacity;

    for (int i=0; i<m_size; ++i){
      newBlock[i] = m_Data[i];
    }
    
    delete[] m_Data;
    m_Data = newBlock;
    m_capacity = newCapacity;
  }

private:
  T* m_Data=nullptr;

  size_t m_size=0;
  size_t m_capacity=0;
};


}// namespace mySTL

