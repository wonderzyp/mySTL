#pragma once

namespace mySTL{

template <typename T>
class vector{
public:

  vector(){
    reallocate(2);
  }

  vector(const vector<T>& other) = delete;

  vector(vector<T>&& other)
  :m_size(other.m_size), m_capacity(other.m_capacity){
    printf("move construction\n");
    
    m_Data = other.m_Data;
    other.m_Data = nullptr;
  }

  vector<T>& operator=(const vector<T>& other){
    printf("copy assignment\n");
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
  }

  vector<T>& operator=(vector<T>&& other){
    printf("move assignment\n");
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
  }

  ~vector(){
    // delete[] m_Data;
    clear(); // 清空内容，调用析构函数
    // 释放内存
    ::operator delete(m_Data, m_capacity*sizeof(T));
  }

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
    m_Data[m_size++] = std::move(elem);
  }

  // 直接原地构造，避免一次移动
  // placement new
  template <typename ...Args>
  T& emplace_back(Args...args){
    if (m_size >= m_capacity)
      reallocate(m_size<<1);

    new (&m_Data[m_size]) T(std::forward<Args>(args)...);
    return m_Data[m_size++];
  }

  void pop_back(){
    if (m_size > 0){
      --m_size;
      m_Data[m_size].~T();
    }
  }



  // 为什么&
  T& operator[](size_t index){return m_Data[index];}
  const T& operator[](size_t index) const {return m_Data[index];}

  size_t size() const {return m_size;}

private:

  //释放内存第一步：清空内存上的内容
  void clear(){
    for (int i=0; i<m_size; ++i){
      m_Data[i].~T();
    }
    m_size = 0;
  }

  void reallocate(size_t newCapacity){
    // 分配内存
    T* newBlock = (T*) ::operator new(newCapacity * sizeof(T));

    // 防止下文越界
    if (newCapacity < m_size) m_size = newCapacity;

    // 将旧数据转移至新分配区域
    for (int i=0; i<m_size; ++i){
      new(&newBlock[i]) T(std::move(m_Data[i]));
    }

    int old_size=m_size;
    clear();
    ::operator delete(m_Data, m_capacity*sizeof(T));
    m_size = old_size;
    m_Data = newBlock;
    m_capacity = newCapacity;
  }



private:
  T* m_Data = nullptr;
  size_t m_size{};
  size_t m_capacity{};
};

}// namespace mySTL

