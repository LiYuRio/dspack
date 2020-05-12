#include <iostream>
#include "dspack/ArrayList.h"
#include "gtest/gtest.h"
#include <vector>
using namespace std;
using namespace dspack;

TEST(ArrayListTest, append) {
  ArrayList<float> a;
  vector<float> v;
  int num_append = 50;
  for (int i = 0; i < num_append; i++) {
    a.append(i);
    v.push_back(i);
  }
  for (int i = 0; i < num_append; i++) {
    EXPECT_EQ(v[i], a[i]);
  }
}

TEST(ArrayListTest, insert) {
  ArrayList<float> a;
  vector<float> v;
  int num_insert = 50;
  for (int i = 0; i < num_insert; i++) {
    a.insert(i, i);
    v.insert(v.begin() + i, i);
  }
  for (int i = 0; i < num_insert; i++) {
    EXPECT_EQ(v[i], a[i]);
  }
}

TEST(ArrayListTest, delete) {
  ArrayList<float> a;
  vector<float> v;
  int num_append = 50;
  int num_delete = 10;
  for (int i = 0; i < num_append; i++) {
    a.append(i);
    v.push_back(i);
  }
  for (int i = 0; i < num_delete; i++) {
    a.remove(i + 10);
    v.erase(v.begin() + i + 10);
  }
  for (int i = 0; i < a.size(); i++) {
    EXPECT_EQ(v[i], a[i]);
  }
}