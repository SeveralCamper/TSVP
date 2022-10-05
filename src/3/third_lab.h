#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <complex>
#include "../array_processing_methods.h"

void print_complex_array(std::complex<double> *complex_array, int size);

std::complex<double> *multiply_arrays_num(std::complex<double> *array_1, int size);
std::complex<double> *discrete_fourier_transform(std::complex<double> *complex_array, int size);
std::complex<double> *reverse_discrete_fourier_transform(std::complex<double> *complex_array, int size);
std::complex<double> *multiply_arrays(std::complex<double> *array_1, std::complex<double> *array_2, int size);
std::complex<double> *semi_fast_fourier_transform(std::complex<double> *complex_array, int rows, int columns);
std::complex<double> *cummon_convolution(std::complex<double> *array_1, std::complex<double> *array_2,
    int size_1, int size_2);
std::complex<double> *reverse_semi_fast_fourier_transform(std::complex<double> *complex_array,
    int rows, int columns);
std::complex<double> *semi_fast_fourier_convolution(std::complex<double> *array_1_convolved,
    std::complex<double> *array_2_covloved, int rows, int columns);

