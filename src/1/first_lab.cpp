#include "first_lab.h"

void bubble_sort(double* array, int array_length) {
  int count_comparisons = 0, count_permutations = 0;
  for (int i = 0; i < array_length - 1; i++) {
    for (int j = 0; j < array_length - 1; j++) {
      count_comparisons++;
      if (array[j] > array[j + 1]) {
        std::swap(array[j], array[j + 1]);
        count_permutations += 1;
      }
    }
  }
  std::cout << "Comparisons: " << count_comparisons << std::endl;
  std::cout << "Permutations: " << count_permutations << std::endl;
}

void select_sort(double* array, int array_length) {
  int min_array_index, count_comparisons = 0, count_permutations = 0;
  for (int i = 0; i < array_length - 1; i++) {
    min_array_index = i;
    for (int j = i + 1; j < array_length; j++) {
      count_comparisons++;
      if (array[j] < array[min_array_index]) {
        min_array_index = j;
      }
    }
    std::swap(array[min_array_index], array[i]);
    count_permutations += 1;
  }
  std::cout << "Comparisons: " << count_comparisons << std::endl;
  std::cout << "Permutations: " << count_permutations << std::endl;
}

void merge_sort(double* array, int array_length) {
  double *tmp_array = new double[array_length];
  int count_comparisons = 0, count_permutations = 0;
  int first_len = 0, second_len = 0;
  int first_iter, second_iter, tmp_iter;

  for (int k = 1; k < array_length; k *= 2) {
    for (int left = 0; left + k < array_length; left += k * 2) {
      first_len = left + k;
      second_len = first_len + k;
      if (second_len > array_length) {
        second_len = array_length;
      }
      tmp_iter = left; first_iter = left; second_iter = first_len;
      while (first_iter < first_len && second_iter < second_len) {
        count_comparisons++;
        if (array[first_iter] <= array[second_iter]) {
          tmp_array[tmp_iter] = array[first_iter++];
        } else {
          tmp_array[tmp_iter] = array[second_iter++];
        }
        tmp_iter++;
      }
      while (first_iter < first_len) {
        tmp_array[tmp_iter++] = array[first_iter++];
      }
      while (second_iter < second_len) {
        tmp_array[tmp_iter++] = array[second_iter++];
      }
      for (tmp_iter = left; tmp_iter < second_len; tmp_iter++) {
        count_permutations++;
        array[tmp_iter] = tmp_array[tmp_iter];
      }
    }
  }
  std::cout << "Comparisons: " << count_comparisons << std::endl;
  std::cout << "Permutations: " << count_permutations << std::endl;
  free(tmp_array);
}

