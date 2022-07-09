#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  int q;
  std::cin >> q;

  for (int i = 0; i < q; i++) {
    int com, b, e;
    std::cin >> com >> b >> e;

    if (com == 0) {
      auto min =
          std::min_element(std::next(a.begin(), b), std::next(a.begin(), e));
      std::cout << *min << std::endl;
    } else if (com == 1) {
      auto max =
          std::max_element(std::next(a.begin(), b), std::next(a.begin(), e));
      std::cout << *max << std::endl;
    }
  }

  return 0;
}