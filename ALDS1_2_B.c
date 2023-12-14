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

void swapI8(i8 *x, i8 *y) {
  i8 tmp = *x;
  *x = *y;
  *y = tmp;
}

void swapI16(i16 *x, i16 *y) {
  i16 tmp = *x;
  *x = *y;
  *y = tmp;
}

void swapI32(i32 *x, i32 *y) {
  i32 tmp = *x;
  *x = *y;
  *y = tmp;
}

void swapI64(i64 *x, i64 *y) {
  i64 tmp = *x;
  *x = *y;
  *y = tmp;
}

void swapU8(u8 *x, u8 *y) {
  u8 tmp = *x;
  *x = *y;
  *y = tmp;
}

void swapU16(u16 *x, u16 *y) {
  u16 tmp = *x;
  *x = *y;
  *y = tmp;
}

void swapU32(u32 *x, u32 *y) {
  u32 tmp = *x;
  *x = *y;
  *y = tmp;
}

void swapU64(u64 *x, u64 *y) {
  u64 tmp = *x;
  *x = *y;
  *y = tmp;
}

void swapF32(f32 *x, f32 *y) {
  f32 tmp = *x;
  *x = *y;
  *y = tmp;
}

void swapF64(f64 *x, f64 *y) {
  f64 tmp = *x;
  *x = *y;
  *y = tmp;
}

#define swap(x, y)                                                             \
  _Generic((x),                                                                \
      i8 *: swapI8,                                                            \
      i16 *: swapI16,                                                          \
      i32 *: swapI32,                                                          \
      i64 *: swapI64,                                                          \
      u8 *: swapU8,                                                            \
      u16 *: swapU16,                                                          \
      u32 *: swapU32,                                                          \
      u64 *: swapU64,                                                          \
      f32 *: swapF32,                                                          \
      f64 *: swapF64)(x, y)

// Preamble end

typedef struct Vector {
  usize length;
  usize capacity;
  usize elementSize;
  void *data;
} Vector;

void constructVector(Vector *vector, usize elementSize, usize len) {
  vector->length = len;
  vector->capacity = len;
  vector->elementSize = elementSize;
  vector->data = malloc(elementSize * len);
}

#define constructVectorOf(vector, type, len)                                   \
  constructVector(vector, sizeof(type), len)

void *vectorGetAddress(Vector *vector, usize index) {
  if (index >= vector->length) {
    printf("index out of range\n");
    exit(1);
  }

  return vector->data + index * vector->elementSize;
}

#define vectorGetAddressAs(vector, type, index)                                \
  ((type *)vectorGetAddress(vector, index))

#define vectorGetAs(vector, type, index)                                       \
  (*(type *)vectorGetAddress(vector, index))

void vectorSet(Vector *vector, usize index, void *value) {
  if (index >= vector->length) {
    printf("index out of range\n");
    exit(1);
  }

  void *target = vectorGetAddress(vector, index);
  memcpy(target, value, vector->elementSize);
}

void destroyVector(Vector *vector) {
  free(vector->data);
  vector->data = NULL;
  vector->length = 0;
  vector->capacity = 0;
  vector->elementSize = 0;
}

void printVector(Vector *vector, char *format) {
  for (usize i = 0; i < vector->length; ++i) {
    if (i > 0) {
      printf(" ");
    }

    printf(format, vectorGetAs(vector, i32, i));
  }

  printf("\n");
}

i32 selectionSort(Vector *a) {
  i32 swapCount = 0;

  for (i32 i = 0; i < a->length; i++) {
    i32 minJ = i;

    for (i32 j = i; j < a->length; j++) {
      if (vectorGetAs(a, i32, j) < vectorGetAs(a, i32, minJ)) {
        minJ = j;
      }
    }

    if (i != minJ) {
      swap(vectorGetAddressAs(a, i32, i), vectorGetAddressAs(a, i32, minJ));
      swapCount++;
    }
  }

  return swapCount;
}

int main() {
  i32 n;
  scanf("%" SCNd32, &n);

  Vector a;
  constructVectorOf(&a, i32, n);

  for (i32 i = 0; i < n; i++) {
    scanf("%" SCNd32, vectorGetAddressAs(&a, i32, i));
  }

  i32 swapCount = selectionSort(&a);
  printVector(&a, "%" PRId32);
  printf("%" PRId32 "\n", swapCount);

  destroyVector(&a);

  return 0;
}