#include "third_lab.h"

int main() {
    int size_1 = 0, size_2 = 0, mult_1 = 0, mult_2 = 0, GLOBAL_OPERATIONS;
    std::cout << "\033c";
    std::cout << "Please, enter the size of the first array: ";
    std::cin >> size_1;
    std::cout << "Please, enter the size of the second array: ";
    std::cin >> size_2;
    std::cout << "Please, enter two multipliers: ";
    std::cin >> mult_1 >> mult_2;
    if (size_1 < 0 || size_2 < 0) {
        throw std::runtime_error("Error: Input size is less ther one");
    }

    std::complex<double> *complex_array = new std::complex<double>[size_1];
    std::complex<double> *complex_array_2 = new std::complex<double>[size_2];
    if (complex_array == nullptr || complex_array_2 == nullptr) {
        throw std::runtime_error("Error: Bad memory alloc");
    }

    int iter = 0;
    double real_part = 0, imaginary_part = 0;
    std::ifstream file("data.txt");
    while (file >> real_part >> imaginary_part && iter < size_1) {
        std::complex<double> new_complex(real_part, imaginary_part);
        complex_array[iter] = new_complex;
        iter++;
    }
    iter = 0;
    std::ifstream file_2("data_2.txt");
    while (file_2 >> real_part >> imaginary_part && iter < size_2) {
        std::complex<double> new_complex(real_part, imaginary_part);
        complex_array_2[iter] = new_complex;
        iter++;
    }

    file.close();
    file_2.close();
    std::cout << "\033c";
    print_complex_array(complex_array, size_1);
    print_complex_array(complex_array_2, size_2);

    std::complex<double> *array = new std::complex<double>[size_1];
    std::complex<double> *array_2 = new std::complex<double>[size_2];
    if (array == nullptr || array_2 == nullptr) {
        throw std::runtime_error("Error: Bad memory alloc");
    }

    std::complex<double> *res_array = new std::complex<double>[size_1 + size_2 - 1];
    if (res_array == nullptr) {
        throw std::runtime_error("Error: Bad memory alloc");
    }

    std::cout << "What lab do you want to see?" << std::endl;
    std::cout << "1. Cummon convolution" << std::endl;
    std::cout << "2. DFFT convolution" << std::endl;
    std::cout << "3. SFFT convolution" << std::endl;
    int bigger_size = 0;
    if (size_1 < size_2) {
        bigger_size = size_2;
    } else if (size_1 >= size_2) {
        bigger_size = size_1;
    }

    if (res_array == nullptr) {
        throw std::runtime_error("Error: Bad memory alloc");
    }
    res_array = common_convolution(complex_array, complex_array_2, size_1, size_2);
    std::cout << "Common Convolved" << std::endl;
    print_complex_array(res_array, size_1 + size_2 - 1);

    std::complex<double> *n_complex_array = new std::complex<double>[bigger_size * 2];
    std::complex<double> *n_complex_array_2 = new std::complex<double>[bigger_size * 2];
    for (int i = 0; i < bigger_size; i++) {
        if (i < size_1) {
            n_complex_array[i] = complex_array[i];
        } else {
            n_complex_array[i] = 0;
        }

        if (i < size_2) {
            n_complex_array_2[i] = complex_array_2[i];
        } else {
            n_complex_array_2[i] = 0;
        }
    }

    array = discrete_fourier_transform(n_complex_array, bigger_size * 2, &GLOBAL_OPERATIONS);
    array_2 = discrete_fourier_transform(n_complex_array_2, bigger_size * 2, &GLOBAL_OPERATIONS);
    res_array = semi_fast_fourier_convolution(array, array_2, mult_1, mult_2, &GLOBAL_OPERATIONS);
    std::cout << "Convolved Discrete Fourier Transform" << std::endl;
    std::cout << "Operations: " << GLOBAL_OPERATIONS << std::endl;
    print_complex_array(res_array, size_1 + size_2 - 1);

    GLOBAL_OPERATIONS = 0;
    array = semi_fast_fourier_transform(n_complex_array, mult_1, mult_2, &GLOBAL_OPERATIONS);
    array_2 = semi_fast_fourier_transform(n_complex_array_2, mult_1, mult_2, &GLOBAL_OPERATIONS);
    res_array = semi_fast_fourier_convolution(array, array_2, mult_1, mult_2, &GLOBAL_OPERATIONS);
    std::cout << "Convolved Semi Fast Fourier Transform" << std::endl;
    std::cout << "Operations: " << GLOBAL_OPERATIONS << std::endl;
    print_complex_array(res_array, size_1 + size_2 - 1);

    return 0;
}
