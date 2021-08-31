#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> seq;
  seq.reserve(n);

  for (int i = 0; i < n; i++) {
    int a;
    std::cin >> a;

    seq.push_back(a);
  }

  for (int i = 0; i < n; i++) {
    std::cout << seq[n - i - 1];

    if (i < n - 1) {
      std::cout << ' ';
    }
  }

  std::cout << std::endl;
  return 0;
}