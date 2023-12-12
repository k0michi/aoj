// Begin preamble

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <cstring>
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
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
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

// End preamble

template <typename T> void scan(std::set<T> &s, usize n) {
  for (i32 i = 0; i < n; i++) {
    i32 x;
    std::cin >> x;
    s.insert(x);
  }
}

template <typename T> void print(std::vector<T> &s) {
  for (auto it = s.begin(); it != s.end(); ++it) {
    std::cout << *it << std::endl;
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i32 n;
  std::cin >> n;
  std::set<i32> a;
  scan(a, n);

  i32 m;
  std::cin >> m;
  std::set<i32> b;
  scan(b, m);

  std::vector<i32> result;

  std::set_difference(std::begin(a), std::end(a), std::begin(b), std::end(b),
                      std::inserter(result, std::end(result)));

  print(result);

  return 0;
}