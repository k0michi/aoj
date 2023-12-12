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
  i32 a, b;
  scanf("%" SCNd32 " %" SCNd32, &a, &b);
  printf("%" PRId32 " %" PRId32 "\n", a * b, 2 * a + 2 * b);
  return 0;
}