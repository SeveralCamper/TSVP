#include "CP_evalution.h"

struct timeval time_val_1, time_val_2, data_time_val;

double time_start() {
  gettimeofday(&time_val_1, NULL);
  return time_val_1.tv_usec;
}

double time_stop() {
  double resault = 0;
  gettimeofday(&time_val_2, NULL);
  data_time_val.tv_sec = time_val_2.tv_sec - time_val_1.tv_sec;
  data_time_val.tv_usec = time_val_2.tv_usec - time_val_1.tv_usec;
  if (data_time_val.tv_usec < 0) {
    data_time_val.tv_sec--;
    data_time_val.tv_usec += 1000000;
  }
  resault = (double)(data_time_val.tv_sec + data_time_val.tv_usec) / 1000;

  return resault;
}

void CPE_check(int matrix_size, int operation_amount) {
  double average_time_common = 0, average_time_fast = 0;
  for (int t = 0; t < operation_amount; t++) {
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

    average_time_common += res_arr[0];
    average_time_fast += res_arr[1];

    // print_matrix(C_common, matrix_size);
    // std::cout << std::endl;
    // print_matrix(C_fast, matrix_size);
  }
  printf("Time common: %lf usec(microsec)\n", average_time_common / operation_amount);
  printf("Time fast: %lf usec(microsec)\n", average_time_fast / operation_amount);

}

/* int main() {
  CPE_check(100, 1);
  return 0;
} */
