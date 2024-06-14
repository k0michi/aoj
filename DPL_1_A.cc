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

i32 solveCoinChanging(const std::vector<i32> &coins, i32 price) {
  i32 coinCount = coins.size();
  std::vector<std::vector<i32>> memo(coinCount + 1,
                                     std::vector<i32>(price + 1, 0));

  std::fill(memo[0].begin(), memo[0].end(), std::numeric_limits<i32>::max());
  memo[0][0] = 0;

  for (i32 i = 1; i <= coinCount; i++) {
    for (i32 j = 0; j <= price; j++) {
      if (j < coins[i - 1]) {
        memo[i][j] = memo[i - 1][j];
      } else {
        memo[i][j] = std::min(memo[i - 1][j], memo[i][j - coins[i - 1]] + 1);
      }
    }
  }

  return memo[coinCount][price];
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i32 n, m;
  std::cin >> n >> m;

  std::vector<i32> c(m);

  for (i32 i = 0; i < m; i++) {
    std::cin >> c[i];
  }

  std::cout << solveCoinChanging(c, n) << std::endl;
  return 0;
}