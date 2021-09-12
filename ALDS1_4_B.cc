#include <iostream>
#include <vector>

int binarySearch(const std::vector<int> &A, int key) {
  int n = A.size();
  int left = 0;
  int right = n;

  while (left < right) {
    int mid = (left + right) / 2;

    if (A[mid] == key) {
      return mid;
    } else if (key < A[mid]) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  return -1;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> S(n);

  for (int i = 0; i < n; i++) {
    std::cin >> S[i];
  }

  int q;
  std::cin >> q;
  std::vector<int> T(q);

  for (int i = 0; i < q; i++) {
    std::cin >> T[i];
  }

  int C = 0;

  for (int i = 0; i < q; i++) {
    if (binarySearch(S, T[i]) != -1) {
      C++;
    }
  }

  std::cout << C << std::endl;
  return 0;
}