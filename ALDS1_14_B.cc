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

constexpr u64 kBase = 100000007;

u64 powInt(u64 base, u64 exp) {
  u64 result = 1;

  for (u64 i = 0; i < exp; i++) {
    result *= base;
  }

  return result;
}

int main() {
  std::string t;
  std::string p;
  std::cin >> t >> p;

  i32 tSize = t.size();
  i32 pSize = p.size();

  u64 basePow = powInt(kBase, pSize);

  u64 tHash = 0;

  for (i32 i = 0; i < pSize; i++) {
    tHash = tHash * kBase + t[i];
  }

  u64 pHash = 0;

  for (i32 i = 0; i < pSize; i++) {
    pHash = pHash * kBase + p[i];
  }

  for (i32 i = 0; i < tSize - pSize + 1; i++) {
    if (tHash == pHash) {
      std::cout << i << std::endl;
    }

    tHash = tHash * kBase + t[i + pSize] - t[i] * basePow;
  }

  return 0;
}