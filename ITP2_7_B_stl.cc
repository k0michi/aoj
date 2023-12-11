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
  i32 q;
  std::cin >> q;
  std::set<i32> set;

  for (i32 i = 0; i < q; i++) {
    i32 op, x;
    std::cin >> op >> x;

    if (op == 0) {
      set.insert(x);
      std::cout << set.size() << std::endl;
    } else if (op == 1) {
      std::cout << (set.find(x) != set.end()) << std::endl;
    } else if (op == 2) {
      set.erase(x);
    }
  }

  return 0;
}