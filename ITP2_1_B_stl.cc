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
  std::deque<i32> deque;
  i32 q;
  std::cin >> q;

  for (int i = 0; i < q; i++) {
    i32 op;
    std::cin >> op;

    if (op == 0) {
      i32 d, x;
      std::cin >> d >> x;

      if (d == 0) {
        deque.push_front(x);
      } else if (d == 1) {
        deque.push_back(x);
      }
    } else if (op == 1) {
      i32 p;
      std::cin >> p;
      std::cout << deque[p] << std::endl;
    } else if (op == 2) {
      i32 d;
      std::cin >> d;

      if (d == 0) {
        deque.pop_front();
      } else if (d == 1) {
        deque.pop_back();
      }
    }
  }

  return 0;
}