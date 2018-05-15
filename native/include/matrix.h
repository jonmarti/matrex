#ifndef INCLUDED_MATRIX_H
#define INCLUDED_MATRIX_H

#include <cblas.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "./utils.h"

typedef float* Matrix;

#define MX_ROWS(matrix) (((uint32_t*)matrix)[0])
#define MX_COLS(matrix) (((uint32_t*)matrix)[1])
#define MX_SET_ROWS(matrix, rows) ((uint32_t*)matrix)[0] = rows
#define MX_SET_COLS(matrix, cols) ((uint32_t*)matrix)[1] = cols
#define MX_LENGTH(matrix) ((((uint32_t*)matrix)[0])*(((uint32_t*)matrix)[1]) + 2)
#define MX_BYTE_SIZE(matrix) ((((uint32_t*)matrix)[0])*(((uint32_t*)matrix)[1]) + 2)*4
#define MX_DATA_BYTE_SIZE(matrix) (((uint32_t*)matrix)[0])*(((uint32_t*)matrix)[1])*4

void
matrix_clone(Matrix destination, Matrix source);

void
matrix_free(Matrix *matrix);

Matrix
matrix_new(uint32_t rows, uint32_t columns);

int32_t
matrix_equal(Matrix first, Matrix second);

void
matrix_add(const Matrix first, const Matrix second, Matrix result);

void
matrix_add_scalar(const Matrix first, const float scalar, Matrix result);

int
matrix_apply(const Matrix matrix, char* function_name, Matrix result);

typedef float (*math_func_ptr_t)(float);

math_func_ptr_t math_func_from_name(const char* name);

int32_t
matrix_argmax(const Matrix matrix);

void
matrix_divide(const Matrix first, const Matrix second, Matrix result);

void
matrix_divide_scalar(const float scalar, const Matrix divisor, Matrix result);

void
matrix_divide_by_scalar(const Matrix dividend, const float scalar, Matrix result);

void
matrix_dot(const Matrix first, const Matrix second, Matrix result);

void
matrix_dot_and_add(
  const Matrix first, const Matrix second, const Matrix third, Matrix result
);

void
matrix_dot_and_apply(
  const float alpha, const Matrix first, const Matrix second, const char *function_name, Matrix result
);

void
matrix_dot_nt(const Matrix first, const Matrix second, Matrix result);

void
matrix_dot_tn(const float alpha, const Matrix first, const Matrix second, Matrix result);

void
matrix_eye(Matrix matrix, const float value);

void
matrix_fill(Matrix matrix, const float value);

float
matrix_first(const Matrix matrix);

void
matrix_inspect(const Matrix matrix);

void
matrix_inspect_internal(const Matrix matrix, int32_t indentation);

float
matrix_max(const Matrix matrix);

void
matrix_multiply(const Matrix first, const Matrix second, Matrix result);

void
matrix_multiply_with_scalar(const Matrix matrix, const float scalar, Matrix result);

void
matrix_neg(const Matrix matrix, Matrix result);

void
matrix_random(Matrix matrix);

void
matrix_set(const Matrix matrix, const uint32_t row, const uint32_t column, const float scalar, Matrix result);

void
matrix_substract(const Matrix first, const Matrix second, Matrix result);

void
matrix_substract_from_scalar(const float scalar, const Matrix matrix, Matrix result);

double
matrix_sum(const Matrix matrix);

void
matrix_transpose(const Matrix matrix, Matrix result);

void
matrix_zeros(Matrix matrix);

#endif
