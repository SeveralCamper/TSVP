#include <gtest/gtest.h>
#include <iostream>

#include "../matrix.h"
#include "../CP_evalution.h"

TEST(matrix_test, matrix_result_100) {
  int matrix_size = 100;
  double *res_arr = new double[2];
  long long int **A = new long long int *[matrix_size];
  long long int **B = new long long int *[matrix_size];
  long long int **C_common = new long long int *[matrix_size];
  long long int **C_fast = new long long int *[matrix_size];
  for (int i = 0; i < matrix_size; i++) {
    A[i] = new long long int[matrix_size];
    B[i] = new long long int[matrix_size];
    C_common[i] = new long long int[matrix_size];
    C_fast[i] = new long long int[matrix_size];
  }

  for (int i = 0; i < matrix_size; i++) {
    for (int j = 0; j < matrix_size; j++) {
      A[i][j] = pow((-1), i + j);
      B[i][j] = i + j;
    }
  }

  time_start();
  C_common = mult_matrix(A, B, matrix_size, 0);
  res_arr[0] = time_stop();

  time_start();
  C_fast = mult_matrix(A, B, matrix_size, 1);
  res_arr[1] = time_stop();

  printf("Time common: %lf usec(microsec)\n", res_arr[0]);
  printf("Time fast: %lf usec(microsec)\n", res_arr[1]);

  for (int i = 0; i < matrix_size; i++) {
    for (int j = 0; j < matrix_size; j++) {
      ASSERT_EQ(C_common[i][j], C_fast[i][j]);
    }
  }
}

/* TEST(matrix_test, matrix_result_average_100) {
  CPE_check(100, 100);
} */

/* TEST(matrix_test, matrix_result_1000) {
  int matrix_size = 1000;
  long long int **A = new long long int *[matrix_size];
  long long int **B = new long long int *[matrix_size];
  long long int **C_common = new long long int *[matrix_size];
  long long int **C_fast = new long long int *[matrix_size];
  for (int i = 0; i < matrix_size; i++) {
    A[i] = new long long int[matrix_size];
    B[i] = new long long int[matrix_size];
    C_common[i] = new long long int[matrix_size];
    C_fast[i] = new long long int[matrix_size];
  }

  for (int i = 0; i < matrix_size; i++) {
    for (int j = 0; j < matrix_size; j++) {
      A[i][j] = pow((-1), i + j);
      B[i][j] = i + j;
    }
  }

  C_common = mult_matrix(A, B, matrix_size, 0);
  C_fast = mult_matrix(A, B, matrix_size, 1);

  for (int i = 0; i < matrix_size; i++) {
    for (int j = 0; j < matrix_size; j++) {
      ASSERT_EQ(C_common[i][j], C_fast[i][j]);
    }
  }
} */

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}