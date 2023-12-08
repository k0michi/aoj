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

int main() {
  i32 n;
  std::cin >> n;
  std::vector<std::tuple<i32, i32>> pairs(n);

  for (i32 i = 0; i < n; i++) {
    std::cin >> std::get<0>(pairs[i]) >> std::get<1>(pairs[i]);
  }

  std::sort(pairs.begin(), pairs.end(), [](auto a, auto b) {
    if (std::get<0>(a) != std::get<0>(b)) {
      return std::get<0>(a) < std::get<0>(b);
    } else {
      return std::get<1>(a) < std::get<1>(b);
    }
  });

  for (auto &&pair : pairs) {
    std::cout << std::get<0>(pair) << ' ' << std::get<1>(pair) << std::endl;
  }

  return 0;
}