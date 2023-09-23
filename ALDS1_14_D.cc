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

// Manber & Myers algorithm
std::vector<i32> constructSuffixArray(const std::string &string) {
  i32 n = string.size();
  std::vector<i32> suffixArray(n + 1);
  std::vector<i32> rank(n + 1);
  std::vector<i32> temp(n + 1);

  for (i32 i = 0; i <= n; i++) {
    suffixArray[i] = i;
    rank[i] = i < n ? string[i] : -1;
  }

  i32 k;

  auto compare = [&](i32 i, i32 j) {
    if (rank[i] != rank[j]) {
      return rank[i] < rank[j];
    }

    i32 ri = i + k <= n ? rank[i + k] : -1;
    i32 rj = j + k <= n ? rank[j + k] : -1;

    return ri < rj;
  };

  for (k = 1; k <= n; k *= 2) {
    std::sort(suffixArray.begin(), suffixArray.end(), compare);

    temp[suffixArray[0]] = 0;

    for (i32 i = 1; i <= n; i++) {
      temp[suffixArray[i]] =
          temp[suffixArray[i - 1]] +
          (compare(suffixArray[i - 1], suffixArray[i]) ? 1 : 0);
    }

    rank = temp;
  }

  return suffixArray;
}

bool contains(const std::vector<i32> &suffixArray, const std::string &string,
              const std::string &pattern) {
  i32 left = 0;
  i32 right = string.size();

  // Binary search
  while (left < right) {
    i32 mid = (left + right) / 2;
    i32 result = string.compare(suffixArray[mid], pattern.size(), pattern);

    if (result < 0) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  return string.compare(suffixArray[right], pattern.size(), pattern) == 0;
}

int main() {
  std::string t;
  i32 q;
  std::cin >> t >> q;

  auto suffixArray = constructSuffixArray(t);

  for (i32 i = 0; i < q; i++) {
    std::string p;
    std::cin >> p;
    std::cout << contains(suffixArray, t, p) << std::endl;
  }

  return 0;
}