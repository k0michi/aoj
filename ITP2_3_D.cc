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

bool lexicographicalCompare(const std::vector<i32> &a,
                            const std::vector<i32> &b) {
  i32 length = std::max(a.size(), b.size());

  for (i32 i = 0; i < length; i++) {
    if (i >= a.size()) {
      // a < b
      return true;
    } else if (i >= b.size()) {
      // a > b
      return false;
    } else if (a[i] != b[i]) {
      return a[i] < b[i];
    }
  }

  // a == b
  return false;
}

int main() {
  i32 n, m;
  std::vector<i32> a, b;

  std::cin >> n;
  a.resize(n);

  for (i32 i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::cin >> m;
  b.resize(m);

  for (i32 i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << i32(lexicographicalCompare(a, b)) << std::endl;

  return 0;
}