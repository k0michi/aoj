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

struct Item {
  i32 v;
  i32 w;
  char t;
  i64 d;
  std::string s;
};

int main() {
  i32 n;
  std::cin >> n;
  std::vector<Item> items(n);

  for (i32 i = 0; i < n; i++) {
    std::cin >> items[i].v >> items[i].w >> items[i].t >> items[i].d >>
        items[i].s;
  }

  std::sort(items.begin(), items.end(), [](auto a, auto b) {
    if (a.v != b.v) {
      return a.v < b.v;
    } else if (a.w != b.w) {
      return a.w < b.w;
    } else if (a.t != b.t) {
      return a.t < b.t;
    } else if (a.d != b.d) {
      return a.d < b.d;
    } else {
      return a.s < b.s;
    }
  });

  for (auto &&i : items) {
    std::cout << i.v << ' ' << i.w << ' ' << i.t << ' ' << i.d << ' ' << i.s
              << std::endl;
  }

  return 0;
}