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

i32 solve01Knapsack(const std::vector<i32> &values,
                    const std::vector<i32> &weights, i32 knapsackSize) {
  i32 itemCount = values.size();
  std::vector<std::vector<i32>> memo(itemCount + 1,
                                     std::vector<i32>(knapsackSize + 1, 0));

  for (i32 i = 1; i <= itemCount; i++) {
    for (i32 j = 0; j <= knapsackSize; j++) {
      if (j < weights[i - 1]) {
        memo[i][j] = memo[i - 1][j];
      } else {
        memo[i][j] = std::max(memo[i - 1][j],
                              memo[i - 1][j - weights[i - 1]] + values[i - 1]);
      }
    }
  }

  return memo[itemCount][knapsackSize];
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i32 N, W;
  std::cin >> N >> W;

  std::vector<i32> v(N), w(N);

  for (i32 i = 0; i < N; i++) {
    std::cin >> v[i] >> w[i];
  }

  std::cout << solve01Knapsack(v, w, W) << std::endl;
  return 0;
}