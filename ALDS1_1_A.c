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

void insertionSort(Vector *vector) {
  i32 n = vector->length;

  for (i32 i = 1; i < n; i++) {
    printVector(vector, "%" PRId32);

    i32 v = vectorGetAs(vector, i32, i);
    i32 j = i - 1;

    while (j >= 0 && vectorGetAs(vector, i32, j) > v) {
      vectorSet(vector, j + 1, vectorGetAddressAs(vector, i32, j));
      j--;
    }

    vectorSet(vector, j + 1, &v);
  }

  printVector(vector, "%" PRId32);
}

int main() {
  i32 n;
  scanf("%" SCNd32, &n);

  Vector a;
  constructVectorOf(&a, i32, n);

  for (i32 i = 0; i < n; ++i) {
    scanf("%" SCNd32, vectorGetAddressAs(&a, i32, i));
  }

  insertionSort(&a);

  destroyVector(&a);
  return 0;
}