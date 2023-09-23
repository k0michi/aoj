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

constexpr u64 kBase1 = 9973;
constexpr u64 kBase2 = 100000007;

u64 powInt(u64 base, u64 exp) {
  u64 result = 1;

  for (u64 i = 0; i < exp; i++) {
    result *= base;
  }

  return result;
}

std::vector<std::vector<u64>>
hashField(const std::vector<std::vector<char>> &field, i32 windowH,
          i32 windowW) {
  i32 fieldH = field.size();
  i32 fieldW = field[0].size();
  i32 hashFieldH = field.size() - windowH + 1;
  i32 hashFieldW = field[0].size() - windowW + 1;

  std::vector<std::vector<u64>> hf(hashFieldH, std::vector<u64>(hashFieldW));
  std::vector<std::vector<u64>> temp(fieldH, std::vector<u64>(hashFieldW));

  u64 base1Pow = powInt(kBase1, windowW);
  u64 base2Pow = powInt(kBase2, windowH);

  // Hash against each row
  for (i32 i = 0; i < fieldH; i++) {
    u64 hash = 0;

    for (i32 j = 0; j < windowW; j++) {
      hash = hash * kBase1 + field[i][j];
    }

    for (i32 j = 0; j < hashFieldW; j++) {
      temp[i][j] = hash;

      if (j + windowW < fieldW) {
        hash = hash * kBase1 + field[i][j + windowW] - field[i][j] * base1Pow;
      }
    }
  }

  // Hash against each column
  for (i32 j = 0; j < hashFieldW; j++) {

    u64 hash = 0;

    for (i32 i = 0; i < windowH; i++) {
      hash = hash * kBase2 + temp[i][j];
    }

    for (i32 i = 0; i < hashFieldH; i++) {
      hf[i][j] = hash;

      if (i + windowH < fieldH) {
        hash = hash * kBase2 + temp[i + windowH][j] - temp[i][j] * base2Pow;
      }
    }
  }

  return hf;
}

int main() {
  i32 h, w;
  std::cin >> h >> w;
  std::vector<std::vector<char>> field(h, std::vector<char>(w));

  for (i32 i = 0; i < h; i++) {
    for (i32 j = 0; j < w; j++) {
      std::cin >> field[i][j];
    }
  }

  i32 r, c;
  std::cin >> r >> c;
  std::vector<std::vector<char>> pattern(r, std::vector<char>(c));

  for (i32 i = 0; i < r; i++) {
    for (i32 j = 0; j < c; j++) {
      std::cin >> pattern[i][j];
    }
  }

  auto fieldHash = hashField(field, r, c);
  auto patternHash = hashField(pattern, r, c);

  for (i32 i = 0; i < fieldHash.size(); i++) {
    for (i32 j = 0; j < fieldHash[0].size(); j++) {
      if (fieldHash[i][j] == patternHash[0][0]) {
        std::cout << i << " " << j << std::endl;
      }
    }
  }

  return 0;
}