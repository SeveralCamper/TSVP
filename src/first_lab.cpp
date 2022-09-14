#include "first_lab.h"

void BubleSort(double* array, int array_length) {
  int count_cpmparisons = 0, count_permutations = 0;
  for (int i = 0; i < array_length - 1; i++) {
    for (int j = 0; j < array_length - 1; j++) {
      count_cpmparisons++;
      if (array[j] > array[j + 1]) {
        std::swap(array[j], array[j + 1]);
        count_permutations += 1;
      }
    }
  }
  std::cout << "Comparisons: " << count_cpmparisons << std::endl;
  std::cout << "Permutations: " << count_permutations << std::endl;
}

void SelectSort(double* array, int array_length) {
  int min_array_index, count_cpmparisons = 0, count_permutations = 0;
  for (int i = 0; i < array_length - 1; i++) {
    min_array_index = i;
    for (int j = i + 1; j < array_length; j++) {
      count_cpmparisons++;
      if (array[j] < array[min_array_index]) {
        min_array_index = j;
      }
    }
    std::swap(array[min_array_index], array[i]);
    count_permutations += 1;
  }
  std::cout << "Comparisons: " << count_cpmparisons << std::endl;
  std::cout << "Permutations: " << count_permutations << std::endl;
}
