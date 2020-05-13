#include <iostream>
#include "dspack/ArrayList.h"
#include "gtest/gtest.h"
#include "utils/random.h"
#include <vector>
using namespace std;
using namespace dspack;

TEST(ArrayListTest, append) {
  ArrayList<int> a(10);
  vector<int> v(10);
  random_uniform(a.data(), a.size(), 1, 10);
  for (int i = 0; i < a.size(); i++) {
    v[i] = a[i];
  }
  const int num_append = 3;
  int append_values[num_append] = {10, 43, 125};
  for (int i = 0;i < num_append;i++) {
    a.append(append_values[i]);
    v.push_back(append_values[i]);
  }
  for (int i = 0; i < a.size(); i++) {
    EXPECT_EQ(v[i], a[i]);
  }
}

TEST(ArrayListTest, insert) {
  const int num_insert = 50;
  float insert_values[num_insert];
  random_normal(insert_values, num_insert, 1, 10);
  ArrayList<float> a;
  vector<float> v;
  for (int i = 0; i < num_insert; i++) {
    a.insert(i, insert_values[i]);
    v.insert(v.begin() + i, insert_values[i]);
  }
  for (int i = 0; i < a.size(); i++) {
    EXPECT_EQ(v[i], a[i]);
  }
}

TEST(ArrayListTest, remove) {
  ArrayList<int> a(20);
  vector<int> v(20);
  random_uniform(a.data(), a.size(), 1, 10);
  for (int i = 0; i < a.size(); i++) {
    v[i] = a[i];
  }
  const int num_remove = 3;
  int remove_index[num_remove] = {1, 14, 12};
  for (int i = 0;i < num_remove;i++) {
    a.remove(remove_index[i]);
    v.erase(v.begin() + remove_index[i]);
  }
  for (int i = 0; i < a.size(); i++) {
    EXPECT_EQ(v[i], a[i]);
  }
}