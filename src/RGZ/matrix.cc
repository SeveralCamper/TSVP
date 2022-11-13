#include "matrix.h"

// Асимптотическая сложность простого умножения O(n^2)
// Асимптотическая сложность умножения Карацубы 3T(n/2) + O(n) ~ O(n^log2(3)) ~
// O(n^1.585)

long long int** mult_matrix(long long int** A, long long int** B,
                            int matrix_size, bool mult_flag) {
  unsigned long long int count_karatsuba_mult_operations = 0,
                         count_native_mult_operations = 0;
  long long int** C = new long long int*[matrix_size];
  for (int i = 0; i < matrix_size; i++) {
    C[i] = new long long int[matrix_size];
  }

  for (int i = 0; i < matrix_size; i++) {
    for (int j = 0; j < matrix_size; j++) {
      for (int k = 0; k < matrix_size; k++) {
        long long int check_length_num = 0, check_length_size = 0;
        check_length_num = A[i][k] * B[k][j];
        while (check_length_num != 0) {
          check_length_num = check_length_num / 10;
          check_length_size++;
        }
        std::vector<int> vector_1 = from_num_to_array(A[i][k]);
        std::vector<int> vector_2 = from_num_to_array(B[k][j]);

        auto N = std::max(vector_1.size(), vector_2.size());

        extend_vec(vector_1, N);
        extend_vec(vector_2, N);

        std::vector<int> vector_3;

        if (!mult_flag) {
          vector_3 =
              native_mul(vector_1, vector_2, count_native_mult_operations);
        } else {
          vector_3 = karatsuba_mul(vector_1, vector_2,
                                   count_karatsuba_mult_operations);
        }
        finalize(vector_3);
        vector_3.resize(check_length_size);

        C[i][j] += from_array_to_num(vector_3, check_length_size);
      }
    }
  }
  if (!mult_flag) {
    std::cout << "count_native_mult_operations: "
              << count_native_mult_operations << std::endl;
  } else {
    std::cout << "count_karatsuba_mult_operations: "
              << count_karatsuba_mult_operations << std::endl;
  }

  return C;
}

// Простое умножение

std::vector<int> native_mul(
    const std::vector<int>& vector_1, const std::vector<int>& vector_2,
    unsigned long long int& count_native_mult_operations) {
  auto len = vector_1.size();
  std::vector<int> result(2 * len);

  for (auto i = 0; i < (int) len; ++i) {
    for (auto j = 0; j < (int) len; ++j) {
      result[i + j] += vector_1[i] * vector_2[j];
      count_native_mult_operations++;
    }
  }

  return result;
}

// Алгоритм Карацубы

void extend_vec(std::vector<int>& vector, int extend_size) {
  while (extend_size & (extend_size - 1)) {
    ++extend_size;
  }

  vector.resize(extend_size);
}

std::vector<int> karatsuba_mul(
    const std::vector<int>& vector_1, const std::vector<int>& vector_2,
    unsigned long long int& count_karatsuba_mult_operations) {
  auto len = vector_1.size();
  std::vector<int> res(2 * len);

  /* if (len < LEN_FOR_NATIVE) {
      return native_mul(vector_1, vector_2, count_karatsuba_mult_operations);
  } */

  if (len == 1) {
    return native_mul(vector_1, vector_2, count_karatsuba_mult_operations);
  }

  auto k = len / 2;

  std::vector<int> Xr{vector_1.begin(), vector_1.begin() + k};
  std::vector<int> Xl{vector_1.begin() + k, vector_1.end()};
  std::vector<int> Yr{vector_2.begin(), vector_2.begin() + k};
  std::vector<int> Yl{vector_2.begin() + k, vector_2.end()};

  std::vector<int> P1 = karatsuba_mul(Xl, Yl, count_karatsuba_mult_operations);
  std::vector<int> P2 = karatsuba_mul(Xr, Yr, count_karatsuba_mult_operations);

  std::vector<int> Xlr(k);
  std::vector<int> Ylr(k);

  for (int i = 0; i < (int) k; ++i) {
    Xlr[i] = Xl[i] + Xr[i];
    Ylr[i] = Yl[i] + Yr[i];
  }

  std::vector<int> P3 =
      karatsuba_mul(Xlr, Ylr, count_karatsuba_mult_operations);

  for (auto i = 0; i < (int) len; ++i) {
    P3[i] -= P2[i] + P1[i];
  }

  for (auto i = 0; i < (int) len; ++i) {
    res[i] = P2[i];
  }

  for (auto i = len; i < (int) 2 * len; ++i) {
    res[i] = P1[i - len];
  }

  for (auto i = k; i < (int) len + k; ++i) {
    res[i] += P3[i - k];
  }
  count_karatsuba_mult_operations = count_karatsuba_mult_operations + 1;

  return res;
}

void finalize(std::vector<int>& res) {
  for (auto i = 0; i < (int) res.size(); ++i) {
    res[i + 1] += res[i] / 10;
    res[i] %= 10;
  }
}

std::vector<int> from_num_to_array(long long int num) {
  int i = 0;
  std::vector<int> res_array;
  while (num != 0) {
    res_array.push_back(num % 10);
    num = num / 10;
    i++;
  }

  return res_array;
}

long long int from_array_to_num(std::vector<int> array, int num_length) {
  long long int res_num = 0;
  long long int degree = 1;
  for (int i = 0; i < num_length; i++) {
    res_num += array[i] * degree;
    degree *= 10;
  }

  return res_num;
}

/* void print_matrix(long long int** matrix, int matrix_size) {
  for (int i = 0; i < matrix_size; i++) {
    for (int j = 0; j < matrix_size; j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
} */