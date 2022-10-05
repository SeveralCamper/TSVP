#include "third_lab.h"

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
    std::complex<double> imaginary_unit(0, 1);
    std::complex<double> *rev_dft_array = new std::complex<double>[size];

    for (int i = 0; i < size; i++) {
        std::complex<double>resault_el(0, 0);
        for (int j = 0; j < size; j++) {
            resault_el += pow(M_E, std::complex<double>(2 * M_PI * j * i) * imaginary_unit /
            (std::complex<double>) size) * (std::complex<double>) complex_array[j];
        }
        rev_dft_array[i] = resault_el;
    }

    return rev_dft_array;
}

std::complex<double> *semi_fast_fourier_transform(std::complex<double> *complex_array,
    int rows, int columns) {
    // int opertions = 0;
    std::complex<double> imaginary_unit(0, 1);
    std::complex<double> **frist_matrix = new std::complex<double> *[rows];
    for (int i = 0; i < rows; i++) {
        frist_matrix[i] = new std::complex<double>[columns];
    }

    std::complex<double> **second_matrix = new std::complex<double> *[rows];
    for (int i = 0; i < rows; i++) {
        second_matrix[i] = new std::complex<double>[columns];
    }

    std::complex<double> element = 0;
    std::cout << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            element = 0;
            for (int k = 0; k < rows; k++) {
                element += (std::complex<double>) complex_array[j + columns * k] * pow(M_E,
                (std::complex<double>(-2 * M_PI  * k * i) * imaginary_unit /
                (std::complex<double>) rows));
            }
            element *= (double)1 /(double) rows;
            frist_matrix[i][j] = element;
        }
    }
    std::cout << std::endl;

    element = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            element = 0;
            for (int k = 0; k < columns; k++) {
                element += frist_matrix[i][k] * pow(M_E,
                (std::complex<double>(-2 * M_PI  * k * (i + rows * j)) * imaginary_unit /
                (std::complex<double>) (rows * columns)));
            }
            element *= (double)1 /(double) columns;
            second_matrix[i][j] = element;
        }
    }

    std::complex<double> *sfft_array = new std::complex<double> [rows * columns];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            sfft_array[j * rows + i] = second_matrix[i][j];
        }
    }

    return sfft_array;
}

std::complex<double> *reverse_semi_fast_fourier_transform(std::complex<double> *complex_array,
    int rows, int columns) {
    // int opertions = 0;
    std::complex<double> imaginary_unit(0, 1);
    std::complex<double> **frist_matrix = new std::complex<double> *[rows];
    for (int i = 0; i < rows; i++) {
        frist_matrix[i] = new std::complex<double>[columns];
    }

    std::complex<double> **second_matrix = new std::complex<double> *[rows];
    for (int i = 0; i < rows; i++) {
        second_matrix[i] = new std::complex<double>[columns];
    }

    std::complex<double> element = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            element = 0;
            for (int k = 0; k < rows; k++) {
                element += complex_array[j + columns * k] * pow(M_E,
                (std::complex<double>(2 * M_PI  * k * i) * imaginary_unit /
                (std::complex<double>) rows));
            }
            frist_matrix[i][j] = element;
        }
    }

    element = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            element = 0;
            for (int k = 0; k < columns; k++) {
                element += frist_matrix[i][k] * pow(M_E,
                (std::complex<double>(2 * M_PI  * k * (i + rows * j)) * imaginary_unit /
                (std::complex<double>) (rows * columns)));
            }
            second_matrix[i][j] = element;
        }
    }

    std::complex<double> *sfft_array = new std::complex<double> [rows * columns];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            sfft_array[j * rows + i] = second_matrix[i][j];
        }
    }

    return sfft_array;
}

std::complex<double> *semi_fast_fourier_convolution(std::complex<double> *array_1, std::complex<double> *array_2, int rows, int columns) {
    std::complex<double> *resault = new std::complex<double>[rows * columns];
    resault = reverse_semi_fast_fourier_transform(multiply_arrays(
        semi_fast_fourier_transform(array_1, rows, columns), semi_fast_fourier_transform(array_2, rows, columns), rows * columns), rows, columns);

    return resault;
}

std::complex<double> *multiply_arrays(std::complex<double> *array_1, std::complex<double> *array_2, int size) {
    std::complex<double> *resault = new std::complex<double>[size];
    for (int i = 0; i < size; i++) {
        resault[i] = array_1[i] * array_2[i];
    }

    return resault;    
}

