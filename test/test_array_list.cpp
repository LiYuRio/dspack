#include <iostream>

#include "ArrayList.h"

using namespace std;

int main() {
  ArrayList<float> a(10);
  a.append(5);
  a.append(10);
  a.append(25);
  a.remove(1);
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}