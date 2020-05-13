#pragma once
#include "utils/iterator_overflow.h"

namespace dspack {
template <typename T>
class ArrayList {
 public:
  ArrayList();
  ArrayList(int init_capacity);
  ~ArrayList();
  ArrayList(const ArrayList& rhs);
  ArrayList& operator=(const ArrayList& rhs);

  void insert(int index, T new_value);
  void append(T new_value);
  T remove(int index);

  bool empty() const;
  int size() const;
  int capacity() const;
  T* data();

  T& operator[](int index);
  T operator[](int index) const;

 private:
  T* _values;
  int _size;
  int _capacity;
  void resize(int new_size);
  void copy(const ArrayList& rhs);
};

template <typename T>
ArrayList<T>::ArrayList() {
  this->_size = 0;
  this->_capacity = 0;
  this->_values = NULL;
}

template <typename T>
ArrayList<T>::ArrayList(int init_capacity) {
  this->_size = init_capacity;
  this->_capacity = init_capacity;
  this->_values = new T[init_capacity];
}

template <typename T>
ArrayList<T>::~ArrayList() {
  delete this->_values;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& rhs) {
  copy(rhs);
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs) {
  copy(rhs);
}

template <typename T>
void ArrayList<T>::insert(int index, T new_value) {
  if (index > this->_size) {
    throw iterator_overflow(index, this->_size);
  }
  if (this->_size >= this->_capacity) {
    resize(this->_capacity * 2 + 10);
  }
  for (int i = this->_size - 1; i >= index; i--) {
    this->_values[i + 1] = this->_values[i];
  }
  this->_values[index] = new_value;
  this->_size += 1;
}

template <typename T>
void ArrayList<T>::append(T new_value) {
  if (this->_size >= this->_capacity) {
    resize(this->_capacity * 2 + 10);
  }
  this->_values[this->_size] = new_value;
  this->_size += 1;
}

template <typename T>
T ArrayList<T>::remove(int index) {
  if (index > this->_size) {
    throw iterator_overflow(index, this->_size);
  }
  if (this->_size <= this->_capacity / 3) {
    resize(this->_size);
  }
  T value = this->_values[index];
  for (int i = index; i < this->_size - 1; i++) {
    this->_values[i] = this->_values[i + 1];
  }
  this->_size -= 1;
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
T* ArrayList<T>::data() {
  return this->_values;
}

template <typename T>
T ArrayList<T>::operator[](int index) const {
  if (index > this->_size) {
    throw iterator_overflow(index, this->_size);
  }
  return this->_values[index];
}

template <typename T>
T& ArrayList<T>::operator[](int index) {
  if (index > this->_size) {
    throw iterator_overflow(index, this->_size);
  }
  return this->_values[index];
}

template <typename T>
void ArrayList<T>::copy(const ArrayList<T>& rhs) {
  this->_size = rhs.size();
  this->_capacity = rhs.capacity();
  this->_values = new T[this->_capacity];
  for (int i = 0; i < rhs.size(); i++) {
    this->_values[i] = rhs[i];
  }
}

template <typename T>
void ArrayList<T>::resize(int new_size) {
  this->_capacity = new_size;
  T* new_values = new T[this->_capacity];
  for (int i = 0; i < this->_size; i++) {
    new_values[i] = this->_values[i];
  }
  delete this->_values;
  this->_values = new_values;
}
}  // namespace dspack