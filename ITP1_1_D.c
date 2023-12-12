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

int main() {
  i32 S;
  scanf("%" SCNd32, &S);
  i32 h, m, s;
  h = S / (60 * 60);
  S -= h * (60 * 60);
  m = S / 60;
  S -= m * 60;
  s = S;
  printf("%" PRId32 ":%" PRId32 ":%" PRId32 "\n", h, m, s);
  return 0;
}