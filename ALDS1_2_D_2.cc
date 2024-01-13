// Preamble begin

#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstring>
#include <deque>
#include <forward_list>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <variant>
#include <vector>

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using isize = std::make_signed<size_t>::type;
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using usize = size_t;
using f32 = float;
using f64 = double;

// Preamble end

i32 count = 0;

template <typename T>
void printVector(std::vector<T> &a, char delimiter = ' ') {
  for (i32 i = 0; i < a.size(); i++) {
    if (i > 0) {
      std::cout << delimiter;
    }

    std::cout << a[i];
  }

  std::cout << std::endl;
}

template <typename T> void insertionSort(std::vector<T> &a, i32 g) {
  i32 n = a.size();

  for (i32 i = g; i < n; i++) {
    i32 v = a[i];
    i32 j = i - g;

    while (j >= 0 && a[j] > v) {
      a[j + g] = a[j];
      j = j - g;
      count++;
    }

    a[j + g] = v;
  }
}

template <typename T> void shellSort(std::vector<T> &a) {
  i32 n = a.size();
  count = 0;

  std::vector<i32> g;

  for (int h = 1; h < n || h == 1; h = 3 * h + 1) {
    g.push_back(h);
  }

  std::reverse(g.begin(), g.end());

  i32 m = g.size();
  std::cout << m << std::endl;
  printVector(g);

  for (i32 i = 0; i < m; i++) {
    insertionSort(a, g[i]);
  }

  std::cout << count << std::endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  std::vector<i32> a(n);

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  shellSort(a);

  printVector(a, '\n');

  return 0;
}