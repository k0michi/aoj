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

i32 gcd(i32 x, i32 y) {
  if (y == 0) {
    return x;
  }

  return gcd(y, x % y);
}

int main() {
  i32 x, y;
  scanf("%" SCNd32 "%" SCNd32, &x, &y);

  printf("%" PRId32 "\n", gcd(x, y));

  return 0;
}