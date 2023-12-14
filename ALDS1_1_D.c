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

i8 minI8(i8 x, i8 y) { return x < y ? x : y; }

i16 minI16(i16 x, i16 y) { return x < y ? x : y; }

i32 minI32(i32 x, i32 y) { return x < y ? x : y; }

i64 minI64(i64 x, i64 y) { return x < y ? x : y; }

u8 minU8(u8 x, u8 y) { return x < y ? x : y; }

u16 minU16(u16 x, u16 y) { return x < y ? x : y; }

u32 minU32(u32 x, u32 y) { return x < y ? x : y; }

u64 minU64(u64 x, u64 y) { return x < y ? x : y; }

#define min(x, y)                                                              \
  _Generic((x),                                                                \
      i8: minI8,                                                               \
      i16: minI16,                                                             \
      i32: minI32,                                                             \
      i64: minI64,                                                             \
      u8: minU8,                                                               \
      u16: minU16,                                                             \
      u32: minU32,                                                             \
      u64: minU64,                                                             \
      f32: fminf,                                                              \
      f64: fmin)(x, y)

i8 maxI8(i8 x, i8 y) { return x > y ? x : y; }

i16 maxI16(i16 x, i16 y) { return x > y ? x : y; }

i32 maxI32(i32 x, i32 y) { return x > y ? x : y; }

i64 maxI64(i64 x, i64 y) { return x > y ? x : y; }

u8 maxU8(u8 x, u8 y) { return x > y ? x : y; }

u16 maxU16(u16 x, u16 y) { return x > y ? x : y; }

u32 maxU32(u32 x, u32 y) { return x > y ? x : y; }

u64 maxU64(u64 x, u64 y) { return x > y ? x : y; }

f32 maxF32(f32 x, f32 y) { return x > y ? x : y; }

f64 maxF64(f64 x, f64 y) { return x > y ? x : y; }

#define max(x, y)                                                              \
  _Generic((x),                                                                \
      i8: maxI8,                                                               \
      i16: maxI16,                                                             \
      i32: maxI32,                                                             \
      i64: maxI64,                                                             \
      u8: maxU8,                                                               \
      u16: maxU16,                                                             \
      u32: maxU32,                                                             \
      u64: maxU64,                                                             \
      f32: fmaxf,                                                              \
      f64: fmax)(x, y)

i8 clampI8(i8 x, i8 min, i8 max) { return minI8(maxI8(x, min), max); }

i16 clampI16(i16 x, i16 min, i16 max) { return minI16(maxI16(x, min), max); }

i32 clampI32(i32 x, i32 min, i32 max) { return minI32(maxI32(x, min), max); }

i64 clampI64(i64 x, i64 min, i64 max) { return minI64(maxI64(x, min), max); }

u8 clampU8(u8 x, u8 min, u8 max) { return minU8(maxU8(x, min), max); }

u16 clampU16(u16 x, u16 min, u16 max) { return minU16(maxU16(x, min), max); }

u32 clampU32(u32 x, u32 min, u32 max) { return minU32(maxU32(x, min), max); }

u64 clampU64(u64 x, u64 min, u64 max) { return minU64(maxU64(x, min), max); }

f32 clampF32(f32 x, f32 min, f32 max) { return fminf(fmaxf(x, min), max); }

f64 clampF64(f64 x, f64 min, f64 max) { return fmin(fmax(x, min), max); }

#define clamp(x, min, max)                                                     \
  _Generic((x),                                                                \
      i8: clampI8,                                                             \
      i16: clampI16,                                                           \
      i32: clampI32,                                                           \
      i64: clampI64,                                                           \
      u8: clampU8,                                                             \
      u16: clampU16,                                                           \
      u32: clampU32,                                                           \
      u64: clampU64,                                                           \
      f32: clampF32,                                                           \
      f64: clampF64)(x, min, max)

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
  i32 n, r;
  scanf("%" SCNd32 "%" SCNd32, &n, &r);

  i32 minR = r;
  i32 maxProfit = INT32_MIN;

  for (i32 i = 1; i < n; i++) {
    scanf("%" SCNd32, &r);

    maxProfit = max(maxProfit, r - minR);
    minR = min(minR, r);
  }

  printf("%" PRId32 "\n", maxProfit);

  return 0;
}