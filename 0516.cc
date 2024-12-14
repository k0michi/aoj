#include <algorithm>
#include <array>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
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

using namespace std::literals;

i64 partialSumMax(const std::vector<i64> &v, i64 k) {
  std::vector<i64> cumulative(v.size() + 1);

  for (i64 i = 0; i < v.size(); i++) {
    cumulative[i + 1] += v[i] + cumulative[i];
  }

  i64 max = std::numeric_limits<i64>::min();

  for (i64 i = 0; i + k <= v.size(); i++) {
    i64 sum = cumulative[i + k] - cumulative[i];
    max = std::max(max, sum);
  }

  return max;
}

int main() {
  i64 n, k;

  while (std::cin >> n >> k, k != 0) {
    std::vector<i64> a(n);
    for (i64 i = 0; i < n; i++) {
      std::cin >> a[i];
    }

    std::cout << partialSumMax(a, k) << std::endl;
  }

exit:
  return 0;
}