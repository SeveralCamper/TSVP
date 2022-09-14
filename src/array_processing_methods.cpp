#include "array_processing_methods.h"

int random(int array_length) {
  return rand() % array_length;
}

void swap(int *xp, int *yp) {
  int tmp = *xp;
  *xp = *yp;
  *yp = tmp;
}

void fill_inc(double *array[], int array_length) {
  for (int i = 0; i < array_length; i++) {
    array[i] += i;
}
}

void fill_dec(double *array[], int array_length) {
  for (int i = 0; array_length > 0; i++, array_length--) {
    *array[i] = (double) array_length - 1;
  }
}

void print_array(double *array[], int array_length) {
  for (int i = 0; i < array_length; i++) {
    if (i == array_length - 1) {
      std::cout << array[i] << std::endl;
    } else {
      std::cout << array[i];
    }
  }
}

void fill_rand(double array[], int array_length, int RigthBorder, int LeftBorder) {
  for (int i = 0; i < array_length; i++) {
    array[i] = random(RigthBorder - LeftBorder + 1) + LeftBorder;
  }
}

int check_sum(double array[], int array_length) {
  int sum = 0;
  for (int i = 0; i < array_length; i++) {
    sum = sum + array[i];
  }
  return sum;
}

int run_number(double array[], int array_length) {
  int k = 0;
  for (int i = 0; i < array_length; i++) {
    if  (array[i] > array[i+1])
    k += 1;
  }
  return k;
}
