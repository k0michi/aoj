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

// p^k
struct Factor {
  i32 p;
  i32 k;
};

// Prime factorization.
std::vector<Factor> factorize(i32 n) {
  std::vector<Factor> s;
  i32 sqrtN = i32(std::sqrt(n));

  for (i32 i = 2; i <= sqrtN; i++) {
    if (n % i == 0) {
      i32 k = 0;

      while (n % i == 0) {
        k++;
        n /= i;
      }

      s.push_back({i, k});
    }

    if (n == 1) {
      break;
    }
  }

  if (n != 1) {
    s.push_back({n, 1});
  }

  return s;
}

i32 phi(Factor f) { return i32(std::pow(f.p, f.k) * (1 - (1. / f.p))); }

i32 phi(i32 n) {
  auto factors = factorize(n);
  i32 result = 1;

  for (auto &&f : factors) {
    result *= phi(f);
  }

  return result;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i32 n;
  std::cin >> n;
  std::cout << phi(n) << std::endl;

  return 0;
}