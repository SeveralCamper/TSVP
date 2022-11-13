#pragma once

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

#define LEN_FOR_NATIVE 128

void finalize(std::vector<int>& res);
void extend_vec(std::vector<int>& vector, int extend_size);
void print_matrix(long long int** matrix, int matrix_size);

std::vector<int> from_num_to_array(long long int num);
std::vector<int> native_mul(
    const std::vector<int>& vector_1, const std::vector<int>& vector_2,
    unsigned long long int& count_native_mult_operations);
std::vector<int> karatsuba_mul(
    const std::vector<int>& vector_1, const std::vector<int>& vector_2,
    unsigned long long int& count_karatsuba_mult_operations);

long long int from_array_to_num(std::vector<int> array, int num_length);

long long int** mult_matrix(long long int** A, long long int** B,
                            int matrix_size, bool mult_flag);
