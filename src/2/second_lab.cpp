#include "second_lab.h"

void print_complex_array(std::complex<double> *complex_array, int size) {
    int iter = 0;
    std::cout << "Your complex array:" << std::endl;
    while (iter < size) {
        std::cout << complex_array[iter] << "i" << std::endl;
        iter++;
    }
}

std::complex<double> *fast_fourier_transform(std::complex<double> *complex_array) {
    return complex_array;
}

std::complex<double> *reverse_fast_fourier_transform(std::complex<double> *complex_array) {
    return complex_array;
}
