#pragma once
#include <iostream>

template <typename T>
class ArrayList {
 public:
  ArrayList();
  ArrayList(int init_capacity);
  ~ArrayList();
  ArrayList(const ArrayList &rhs);
  ArrayList& operator=(const ArrayList &rhs);

  void insert(int index, T new_value);
  void append(T new_value);
  T remove(int index);

  bool empty() const;
  int size() const;
  int capacity() const;

  T& operator[](int index); 
  T operator[](int index) const; 

 private:
  T *values;
  int _size;
  int _capacity;
  void resize(int new_size);
  void copy(const ArrayList &rhs);
};

template <typename T>
ArrayList<T>::ArrayList() {
  this->_size = 0;
  this->_capacity = 0;
}

template <typename T>
ArrayList<T>::ArrayList(int init_capacity) {
  this->_size = 0;
  this->_capacity = init_capacity;
  this->values = new T[init_capacity];
}

template <typename T>
ArrayList<T>::~ArrayList() {
  delete this->values;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& rhs) {
  copy(rhs);
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T> &rhs) {
  copy(rhs);
}

template <typename T>
void ArrayList<T>::insert(int index, T new_value) {
  if (index >= this->_size) {
    std::cout << "Invaild index" << std::endl;
    return;
  }
  for (int i = this->_size - 1; i >= index; i--) {
    this->values[i + 1] = this->values[i];
  }
  this->values[index] = new_value;
  this->_size += 1;
  if (this->_size >= this->_capacity * 2 / 3) {
    resize(this->_capacity * 2);
  }
}

template <typename T>
void ArrayList<T>::append(T new_value) {
  this->values[this->_size] = new_value;
  this->_size += 1;
  if (this->_size >= this->_capacity * 2 / 3) {
    resize(this->_capacity * 2);
  }
}

template <typename T>
T ArrayList<T>::remove(int index) {
  if (index >= this->_size) {
    std::cout << "Invaild index" << std::endl;
    exit(-1);
  }
  T value = this->values[index];
  for (int i = index; i < this->_size - 1; i++) {
    this->values[i] = this->values[i + 1];
  }
  this->_size -= 1;
  if (this->_size <= this->_capacity / 3) {
    resize(this->_capacity / 2);
  }
  return value;
}

template <typename T>
bool ArrayList<T>::empty() const {
  if (this->_size == 0) {
    return true;
  }
  return false;
}

template <typename T>
int ArrayList<T>::capacity() const {
  return this->_capacity;
}

template <typename T>
int ArrayList<T>::size() const {
  return this->_size;
}

template <typename T>
T ArrayList<T>::operator[](int index) const {
  if (index >= this->_size) {
    std::cout << "Invaild index" << std::endl;
    exit(-1);
  }
  return this->values[index];
}

template <typename T>
T& ArrayList<T>::operator[](int index) {
  if (index >= this->_size) {
    std::cout << "Invaild index" << std::endl;
    exit(-1);
  }
  return this->values[index];
}

template <typename T>
void ArrayList<T>::copy(const ArrayList<T> &rhs)  {
  this->_size = rhs.size();
  this->_capacity = rhs.capacity();
  this->values = new T[this->_capacity];
  for (int i = 0;i < rhs.size();i++) {
    this->values[i] = rhs[i];
  }
}

template <typename T>
void ArrayList<T>::resize(int new_size) {
  this->_capacity = new_size;
  T* new_values = new T[this->_capacity];
  for (int i = 0; i < this->_size; i++) {
    new_values[i] = this->values[i];
  }
  delete this->values;
  this->values = new_values;
}

// template <typename T>
// std::ostream &operator<<(std::ostream &os, const ArrayList<T> &rhs) {
//   os << "( " << rhs.size() << ", " << rhs.capacity() << " )" << std::endl;
//   for (int i = 0; i < rhs.size(); i++) {
//     os << rhs[i] << " ";
//   }
//   os << std::endl;
// }