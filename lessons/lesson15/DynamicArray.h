//
// Created by pdzhambazov on 26.07.18.
//

#ifndef IVA_DYNAMICARRAY_H
#define IVA_DYNAMICARRAY_H
template<class T>
class DynamicArray {
 private:
  T *m_array;
  int m_length;
 public:
  explicit DynamicArray(int length) : m_length(length), m_array(new T[length]) {}
  ~DynamicArray() {
    delete[] m_array;
  }

  DynamicArray(const DynamicArray &arr) = delete;
  DynamicArray &operator=(const DynamicArray &arr) = delete;

  DynamicArray(DynamicArray &&arr) noexcept : m_length(arr.m_length), m_array(arr.m_array) {
    arr.m_length = 0;
    arr.m_array = nullptr;
  }
  DynamicArray &operator=(DynamicArray &&arr) {
    if (&arr == this) {
      return *this;
    }

    delete[] m_array;
    m_length = arr.m_length;
    m_array = arr.m_array;
    arr.m_length = 0;
    arr.m_array = nullptr;

    return *this;
  }
  int getLength() { return m_length; }
  T &operator[](int index) { return m_array[index]; }
  const T &operator[](int index) const { return m_array[index]; }
};

#endif //IVA_DYNAMICARRAY_H
