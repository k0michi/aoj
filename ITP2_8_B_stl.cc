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

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i32 q;
  std::cin >> q;
  std::map<std::string, i32> map;

  for (i32 i = 0; i < q; i++) {
    i32 op;
    std::string key;
    std::cin >> op >> key;

    if (op == 0) {
      i32 x;
      std::cin >> x;
      map[key] = x;
    } else if (op == 1) {
      i32 x = map[key];
      std::cout << x << std::endl;
    } else if (op == 2) {
      map[key] = 0;
    }
  }

  return 0;
}