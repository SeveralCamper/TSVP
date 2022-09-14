#include "first_lab.h"

void BubleSort(double *array[], int array_length) {
  int tmp, count_cpmparisons, count_permutations;
  for (int i = 0; i < array_length - 1; i++) {
    for (int j = 0; j < array_length - 1; j++) {
      count_cpmparisons++;
      if (array[j] > array[j + 1]) {
          tmp = array[j];
          array[j] = array[j + 1];
          array[j + 1] = tmp;
          count_permutations += 3;
      }
    }
  }
  std::cout << "Comparisons: " << count_cpmparisons << std::endl;
  std::cout << "Permutations: " << count_permutations << std::endl;
}

void SelectSort(double * array, int array_length) {
	int min_array_index, count_cpmparisons, count_permutations;
  for (int i = 0; i < array_length - 1; i++) {
    min_array_index = i;
    count_permutations++;
    for (int j = i + 1; j < array_length; j++) {
      count_cpmparisons++;
      if (array[j] < array[min_array_index]) {
        min_array_index = j;
        count_permutations++
      }
    }
    std::swap(&array[min_array_index],&array[i]);
  }
  std::cout << "Comparisons: " << count_cpmparisons << std::endl;
  std::cout << "Permutations: " << count_permutations << std::endl;
}