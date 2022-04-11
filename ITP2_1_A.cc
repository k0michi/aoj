#include <cstring>
#include <iostream>
#include <string>

struct Vector {
  int size;
  int capacity;
  int *data;

  Vector() : size(0), capacity(16), data(new int[capacity]) {}

  void pushBack(int value) {
    if (size > capacity - 1) {
      int newCapacity = capacity * 2;
      int *newData = new int[newCapacity];
      memcpy(newData, data, capacity * sizeof(int));
      delete data;
      capacity = newCapacity;
      data = newData;
    }

    data[size] = value;
    size++;
  }

  void popBack() { size--; }

  int operator[](int i) { return data[i]; }
};

int main() {
  Vector vector;
  int q;
  std::cin >> q;

  for (int i = 0; i < q; i++) {
    int op;
    std::cin >> op;

    if (op == 0) {
      int x;
      std::cin >> x;
      vector.pushBack(x);
    } else if (op == 1) {
      int p;
      std::cin >> p;
      std::cout << vector[p] << std::endl;
    } else if (op == 2) {
      vector.popBack();
    }
  }

  return 0;
}