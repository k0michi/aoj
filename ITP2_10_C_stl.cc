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

  i32 q;
  std::cin >> q;
  std::bitset<64> flags;

  for (i32 j = 0; j < q; j++) {
    i32 op, i;
    std::cin >> op;

    switch (op) {
    case 0:
    case 1:
    case 2:
    case 3:
      std::cin >> i;
      break;
    default:
      break;
    }

    switch (op) {
    case 0:
      std::cout << flags.test(i) << std::endl;
      break;
    case 1:
      flags.set(i, true);
      break;
    case 2:
      flags.set(i, false);
      break;
    case 3:
      flags.flip(i);
      break;
    case 4:
      std::cout << flags.all() << std::endl;
      break;
    case 5:
      std::cout << flags.any() << std::endl;
      break;
    case 6:
      std::cout << flags.none() << std::endl;
      break;
    case 7:
      std::cout << flags.count() << std::endl;
      break;
    case 8:
      std::cout << flags.to_ullong() << std::endl;
      break;
    }
  }

  return 0;
}