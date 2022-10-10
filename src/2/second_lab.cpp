#include "second_lab.h"

void print_complex_array(std::complex<double> *complex_array, int size) {
    int iter = 0;
    std::cout << "Your complex array:" << std::endl;
    while (iter < size) {
        std::cout.precision(10);
        std::cout << std::fixed << complex_array[iter] << std::endl;
        iter++;
    }
}

std::complex<double> *discrete_fourier_transform(std::complex<double> *complex_array, int size) {
    int opertions = 0;
    std::complex<double> imaginary_unit(0, 1);
    std::complex<double> *dft_array = new std::complex<double>[size];

    for (int i = 0; i < size; i++) {
        std::complex<double>resault_el(0, 0);
        for (int j = 0; j < size; j++) {
            opertions += 5;
            resault_el += pow(M_E, std::complex<double>(-2 * M_PI * j * i) * imaginary_unit /
            (std::complex<double>) size) * (std::complex<double>) complex_array[j];
        }
        resault_el *= ((double)1 / (double)size);
        dft_array[i] = resault_el;
    }

    std::cout << opertions << std::endl;

    return dft_array;
}

std::complex<double> *reverse_discrete_fourier_transform(std::complex<double> *complex_array, int size) {
    int opertions = 0;
    std::complex<double> imaginary_unit(0, 1);
    std::complex<double> *rev_dft_array = new std::complex<double>[size];

    for (int i = 0; i < size; i++) {
        std::complex<double>resault_el(0, 0);
        for (int j = 0; j < size; j++) {
            opertions += 5;
            resault_el += pow(M_E, std::complex<double>(2 * M_PI * j * i) * imaginary_unit /
            (std::complex<double>) size) * (std::complex<double>) complex_array[j];
        }
        rev_dft_array[i] = resault_el;
    }
    std::cout << opertions << std::endl;

    return rev_dft_array;
}
