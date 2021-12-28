#include <iostream>
#include <vector>

int main() {
  int H;
  std::cin >> H;
  std::vector<int> A(H);

  for (int i = 0; i < H; i++) {
    std::cin >> A[i];
  }

  for (int i = 0; i < H; i++) {
    int id = i + 1;
    int k = A[i];
    std::cout << "node " << id << ": key = " << k << ", ";
    int parent = (i + 1) / 2;
    int left = 2 * (i + 1);
    int right = 2 * (i + 1) + 1;

    if (parent >= 1) {
      int pk = A[parent - 1];
      std::cout << "parent key = " << pk << ", ";
    }

    if (left <= H) {
      int lk = A[left - 1];
      std::cout << "left key = " << lk << ", ";
    }

    if (right <= H) {
      int rk = A[right - 1];
      std::cout << "right key = " << rk << ", ";
    }

    std::cout << std::endl;
  }

  return 0;
}