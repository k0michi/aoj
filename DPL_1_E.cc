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

constexpr i32 kInsertDeleteCost = 1;
constexpr i32 kReplaceCost = 1;

i32 levenshtein(const std::string &s1, const std::string &s2) {
  std::vector<std::vector<i32>> memo(s1.size() + 1,
                                     std::vector<i32>(s2.size() + 1, 0));

  for (i32 i = 0; i <= s1.size(); i++) {
    memo[i][0] = kInsertDeleteCost * i;
  }

  for (i32 i = 0; i <= s2.size(); i++) {
    memo[0][i] = kInsertDeleteCost * i;
  }

  for (i32 i = 1; i <= s1.size(); i++) {
    for (i32 j = 1; j <= s2.size(); j++) {
      i32 costIfReplace = 0;

      if (s1[i - 1] != s2[j - 1]) {
        costIfReplace += kReplaceCost;
      }

      memo[i][j] = std::min({memo[i - 1][j - 1] + costIfReplace,
                             memo[i - 1][j] + kInsertDeleteCost,
                             memo[i][j - 1] + kInsertDeleteCost});
    }
  }

  return memo[s1.size()][s2.size()];
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::string s1, s2;
  std::cin >> s1 >> s2;

  std::cout << levenshtein(s1, s2) << std::endl;
  return 0;
}