// Begin preamble

#include <algorithm>
#include <array>
#include <bitset>
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

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i32 n;
  std::cin >> n;
  i32 k;
  std::cin >> k;
  i32 b = 0;

  for (i32 i = 0; i < k; i++) {
    i32 x;
    std::cin >> x;
    b |= 1 << x;
  }

  i32 twoPowN = 1 << n;

  for (i32 i = 0; i < twoPowN; i++) {
    if ((i & b) != b) {
      continue;
    }

    std::cout << i << ":";

    for (i32 j = 0; j < n; j++) {
      i32 twoPowJ = 1 << j;

      if ((i & twoPowJ) != 0) {
        std::cout << ' ' << j;
      }
    }

    std::cout << std::endl;
  }

  return 0;
}