#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <complex>
#include "../array_processing_methods.h"

void print_complex_array(std::complex<double> *complex_array, int size);

std::complex<double> *fast_fourier_transform(std::complex<double> *complex_array);
std::complex<double> *reverse_fast_fourier_transform(std::complex<double> *complex_array);
