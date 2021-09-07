#include <iostream>
#include <utility>
#include <vector>

int bubbleSort(std::vector<int> &seq) {
  int i = 0, opCount = 0;
  bool flag = true;

  while (flag) {
    flag = false;

    for (int j = seq.size() - 1; j >= i + 1; j--) {
      if (seq[j] < seq[j - 1]) {
        std::swap(seq[j], seq[j - 1]);
        flag = true;
        opCount++;
      }
    }

    i++;
  }

  return opCount;
}

int main() {
  int n;
  std::cin >> n;

  std::vector<int> A(n);

  for (int i = 0; i < n; i++) {
    std::cin >> A[i];
  }

  int opCount = bubbleSort(A);

  for (int i = 0; i < n; i++) {
    std::cout << A[i];

    if (i < n - 1) {
      std::cout << ' ';
    }
  }

  std::cout << std::endl;
  std::cout << opCount << std::endl;
  return 0;
}