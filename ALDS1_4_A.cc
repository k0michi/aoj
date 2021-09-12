#include <iostream>
#include <vector>

int linearSearch(std::vector<int> &A, int key) {
  int n = A.size();
  A.push_back(key);

  int i = 0;

  while (A[i] != key) {
    i++;
  }

  if (i == n) {
    return -1;
  }

  return i;
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
    if (linearSearch(S, T[i]) != -1) {
      C++;
    }
  }

  std::cout << C << std::endl;
  return 0;
}