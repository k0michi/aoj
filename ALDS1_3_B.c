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
typedef ptrdiff_t isize;
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

void swapVoid(void *x, void *y, usize size) {
  u8 tmp[size];
  memcpy(tmp, x, size);
  memcpy(x, y, size);
  memcpy(y, tmp, size);
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

#define ANSI_FORE_RED "\x1b[31m"
#define ANSI_RESET "\x1b[0m"

void throw(char *message) {
  printf(ANSI_FORE_RED "%s\n" ANSI_RESET, message);
  exit(1);
}

typedef struct Vector {
  usize length;
  usize capacity;
  usize elementSize;
  void *data;
} Vector;

void constructVector(Vector *vector, usize elementSize, usize len) {
  vector->length = len;
  vector->capacity = max(1, len);
  vector->elementSize = elementSize;
  vector->data = malloc(vector->elementSize * vector->capacity);
}

#define constructVectorOf(vector, type, len)                                   \
  constructVector(vector, sizeof(type), len)

void *vectorGetAddress(Vector *vector, usize index) {
  if (index >= vector->length) {
    throw("index out of range: vectorGetAddress");
  }

  return vector->data + index * vector->elementSize;
}

#define vectorGetAddressAs(vector, type, index)                                \
  ((type *)vectorGetAddress(vector, index))

#define vectorGetAs(vector, type, index)                                       \
  (*(type *)vectorGetAddress(vector, index))

void vectorSet(Vector *vector, usize index, void *value) {
  if (index >= vector->length) {
    throw("index out of range: vectorSet");
  }

  void *target = vectorGetAddress(vector, index);
  memcpy(target, value, vector->elementSize);
}

usize vectorSize(Vector *vector) { return vector->length; }

usize vectorCapacity(Vector *vector) { return vector->capacity; }

usize vectorElementSize(Vector *vector) { return vector->elementSize; }

bool vectorEquals(Vector *a, Vector *b) {
  if (a->length != b->length) {
    return false;
  }

  for (usize i = 0; i < a->length; ++i) {
    if (memcmp(vectorGetAddress(a, i), vectorGetAddress(b, i),
               a->elementSize) != 0) {
      return false;
    }
  }

  return true;
}

void vectorReserve(Vector *vector, usize newCapacity) {
  if (newCapacity > vector->capacity) {
    vector->capacity = newCapacity;
    vector->data = realloc(vector->data, vector->elementSize * newCapacity);
  }
}

void vectorResize(Vector *vector, usize newLength) {
  if (newLength > vector->capacity) {
    vectorReserve(vector, newLength);
  }

  vector->length = newLength;
}

void vectorPushBack(Vector *vector, void *value) {
  if (vector->length == vector->capacity) {
    vectorReserve(vector, vector->capacity * 2);
  }

  usize index = vector->length;
  vector->length++;
  vectorSet(vector, index, value);
}

void vectorPopBack(Vector *vector) {
  if (vector->length == 0) {
    throw("vector length is zero");
  }

  vector->length--;
}

void *vectorFront(Vector *vector) {
  if (vector->length == 0) {
    throw("vector length is zero");
  }

  return vectorGetAddress(vector, 0);
}

#define vectorFrontAs(vector, type) (*(type *)vectorFront(vector))

void *vectorBack(Vector *vector) {
  if (vector->length == 0) {
    throw("vector length is zero");
  }

  return vectorGetAddress(vector, vector->length - 1);
}

#define vectorBackAs(vector, type) (*(type *)vectorBack(vector))

void vectorCopy(Vector *dst, Vector *src) {
  vectorResize(dst, src->length);
  memcpy(dst->data, src->data, src->elementSize * src->length);
}

void destroyVector(Vector *vector) {
  free(vector->data);
  vector->data = NULL;
  vector->length = 0;
  vector->capacity = 0;
  vector->elementSize = 0;
}

typedef struct Deque {
  usize begin;
  usize end;
  usize capacity;
  usize elementSize;
  void *data;
} Deque;

void constructDeque(Deque *deque, usize elementSize, usize len) {
  deque->elementSize = elementSize;
  deque->begin = 0;
  deque->end = len;
  deque->capacity = max(1, len);
  deque->data = malloc(deque->elementSize * deque->capacity);
}

#define constructDequeOf(deque, type, len)                                     \
  constructDeque(deque, sizeof(type), len)

void destroyDeque(Deque *deque) {
  free(deque->data);
  deque->data = NULL;
  deque->begin = 0;
  deque->end = 0;
  deque->capacity = 0;
  deque->elementSize = 0;
}

usize dequeSize(Deque *deque) { return deque->end - deque->begin; }

void *dequeGetAddress(Deque *deque, usize index) {
  if (index >= dequeSize(deque)) {
    throw("index out of range: dequeGetAddress");
  }

  return deque->data + (deque->begin + index) * deque->elementSize;
}

#define dequeGetAddressAs(deque, type, index)                                  \
  ((type *)dequeGetAddress(deque, index))

#define dequeGetAs(deque, type, index) (*(type *)dequeGetAddress(deque, index))

void dequeSet(Deque *deque, usize index, void *value) {
  if (index >= dequeSize(deque)) {
    throw("index out of range: dequeSet");
  }

  void *target = dequeGetAddress(deque, index);
  memcpy(target, value, deque->elementSize);
}

void dequeReserve(Deque *deque, usize newCapacity) {
  if (newCapacity > deque->capacity) {
    usize addCapacity = newCapacity - deque->capacity;
    usize addCapacityFront = addCapacity / 2;
    usize length = dequeSize(deque);
    usize newBegin = addCapacityFront;
    usize newEnd = newBegin + length;

    deque->data = realloc(deque->data, deque->elementSize * newCapacity);
    memmove(deque->data + newBegin * deque->elementSize,
            deque->data + deque->begin * deque->elementSize,
            deque->elementSize * length);

    deque->begin = newBegin;
    deque->end = newEnd;
    deque->capacity = newCapacity;
  }
}

void dequeReserveWithoutMoving(Deque *deque, usize newCapacity) {
  if (newCapacity > deque->capacity) {
    deque->data = realloc(deque->data, deque->elementSize * newCapacity);
    deque->capacity = newCapacity;
  }
}

void dequeResize(Deque *deque, usize newLength) {
  if (newLength > deque->capacity) {
    dequeReserveWithoutMoving(deque, newLength);
  }

  usize length = dequeSize(deque);
  usize newBegin = (deque->capacity - newLength) / 2;
  usize newEnd = newBegin + length;

  memmove(deque->data + newBegin * deque->elementSize,
          deque->data + deque->begin * deque->elementSize,
          deque->elementSize * length);

  deque->begin = newBegin;
  deque->end = newEnd;
}

void dequePushBack(Deque *deque, void *value) {
  if (deque->end == deque->capacity) {
    dequeReserve(deque, deque->capacity * 2);
  }

  usize index = dequeSize(deque);
  deque->end++;
  dequeSet(deque, index, value);
}

void dequePushFront(Deque *deque, void *value) {
  if (deque->begin == 0) {
    dequeReserve(deque, deque->capacity * 2);
  }

  deque->begin--;
  dequeSet(deque, 0, value);
}

void dequePopBack(Deque *deque) {
  if (dequeSize(deque) == 0) {
    throw("deque size is zero");
  }

  deque->end--;
}

void dequePopFront(Deque *deque) {
  if (dequeSize(deque) == 0) {
    throw("deque size is zero");
  }

  deque->begin++;
}

void *dequeFrontAddress(Deque *deque) {
  if (dequeSize(deque) == 0) {
    throw("deque size is zero");
  }

  return dequeGetAddress(deque, 0);
}

#define dequeFrontAs(deque, type) (*(type *)dequeFrontAddress(deque))

void *dequeBackAddress(Deque *deque) {
  if (dequeSize(deque) == 0) {
    throw("deque size is zero");
  }

  return dequeGetAddress(deque, dequeSize(deque) - 1);
}

#define dequeBackAs(deque, type) (*(type *)dequeBackAddress(deque))

bool dequeEmpty(Deque *deque) { return dequeSize(deque) == 0; }

// Preamble end

typedef struct Process {
  char name[11];
  i32 time;
} Process;

int main() {
  i32 n, q;
  scanf("%" SCNd32 "%" SCNd32, &n, &q);

  Deque processes;
  constructDequeOf(&processes, Process, 0);
  i32 currentTime = 0;

  for (i32 i = 0; i < n; i++) {
    Process process;
    scanf("%s %" SCNd32, process.name, &process.time);
    dequePushBack(&processes, &process);
  }

  while (!dequeEmpty(&processes)) {
    Process process = dequeFrontAs(&processes, Process);
    dequePopFront(&processes);

    if (process.time > q) {
      process.time -= q;
      currentTime += q;
      dequePushBack(&processes, &process);
    } else {
      currentTime += process.time;
      printf("%s %" PRId32 "\n", process.name, currentTime);
    }
  }

  return 0;
}