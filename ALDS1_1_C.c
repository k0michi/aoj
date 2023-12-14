// Preamble begin

#include <ctype.h>
#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef size_t usize;
typedef float f32;
typedef double f64;

// Preamble end

bool isPrime(i32 x) {
  if (x == 2) {
    return true;
  }

  if (x < 2 || x % 2 == 0) {
    return false;
  }

  i32 sqrtX = (i32)sqrt(x);

  for (i32 i = 3; i <= sqrtX; i += 2) {
    if (x % i == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  i32 n;
  scanf("%" SCNd32, &n);

  i32 count = 0;

  for (i32 i = 0; i < n; i++) {
    i32 x;
    scanf("%" SCNd32, &x);

    if (isPrime(x)) {
      count++;
    }
  }

  printf("%" PRId32 "\n", count);

  return 0;
}