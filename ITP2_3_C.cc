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
    int b, e, k;
    std::cin >> b >> e >> k;

    int count = std::count(std::next(a.begin(), b), std::next(a.begin(), e), k);
    std::cout << count << std::endl;
  }

  return 0;
}