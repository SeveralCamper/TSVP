#include "third_lab.h"

int main() {
    int flag = 0;

    int size = 0;
    std::cout << "\033c";
    std::cout << "Please, enter the size of the array: ";
    std::cin >> size;
    if (size < 0) {
        throw std::runtime_error("Error: Input size is less ther one");
    }
    std::complex<double> *complex_array = new std::complex<double>[size];
    std::complex<double> *complex_array_2 = new std::complex<double>[size];
    if (complex_array == nullptr || complex_array_2 == nullptr) {
        throw std::runtime_error("Error: Bad memory alloc");
    }

    int iter = 0;
    double real_part = 0, imaginary_part = 0;
    std::ifstream file("data.txt");
    while (file >> real_part >> imaginary_part && iter < size) {
        std::complex<double> new_complex(real_part, imaginary_part);
        complex_array[iter] = new_complex;
        complex_array_2[iter] = new_complex;
        iter++;
    }
    file.close();
    std::cout << "\033c";
    print_complex_array(complex_array, size);
    print_complex_array(complex_array_2, size);

    std::complex<double> *dft_array = new std::complex<double>[size];
    if (dft_array == nullptr) {
        throw std::runtime_error("Error: Bad memory alloc");
    }

    std::complex<double> *array = new std::complex<double>[size];
    std::complex<double> *array_2 = new std::complex<double>[size];
    if (array == nullptr || array_2 == nullptr) {
        throw std::runtime_error("Error: Bad memory alloc");
    }

    std::complex<double> *res_array = new std::complex<double>[size];
    if (res_array == nullptr) {
        throw std::runtime_error("Error: Bad memory alloc");
    }

    std::cout << "What lab do you want to see?" << std::endl;
    std::cout << "1. Cummon convolution" << std::endl;
    std::cout << "2. DFFT convolution" << std::endl;
    std::cout << "3. SFFT convolution" << std::endl;
    std::cin >> flag;
    if (flag == 1) {
        dft_array = discrete_fourier_transform(complex_array, size);
        std::cout << "Discrete Fourier Transform" << std::endl;
        print_complex_array(dft_array, size);

        res_array = semi_fast_fourier_transform(complex_array, 4, 2);
        std::cout << "Semi Fast Fourier Transform" << std::endl;
        print_complex_array(res_array, size);

        std::complex<double> *res_array = new std::complex<double>[size];
        if (res_array == nullptr) {
            throw std::runtime_error("Error: Bad memory alloc");
        }
        res_array = cummon_convolution(res_array, 4, 2);
        std::cout << "Cummon Convolved" << std::endl;
        print_complex_array(res_array, size);
    } else if (flag == 2) {
        array = discrete_fourier_transform(complex_array, 8);
        // std::cout << "Semi Fast Fourier Transform arr_1" << std::endl;
        // print_complex_array(sfft_array, size);
        array_2 = discrete_fourier_transform(complex_array_2, 8);
        // std::cout << "Semi Fast Fourier Transform arr_2" << std::endl;
        // print_complex_array(sfft_array_2, size);
        res_array = semi_fast_fourier_convolution(array, array_2, 4, 2);
        std::cout << "Convolved Discrete Fourier Transform" << std::endl;
        print_complex_array(res_array, size);
    } else if (flag == 3) {
        array = semi_fast_fourier_transform(complex_array, 4, 2);
        // std::cout << "Semi Fast Fourier Transform arr_1" << std::endl;
        // print_complex_array(sfft_array, size);
        array_2 = semi_fast_fourier_transform(complex_array_2, 4, 2);
        // std::cout << "Semi Fast Fourier Transform arr_2" << std::endl;
        // print_complex_array(sfft_array_2, size);
        res_array = semi_fast_fourier_convolution(array, array_2, 4, 2);
        std::cout << "Convolved Semi Fast Fourier Transform" << std::endl;
        print_complex_array(res_array, size);
    } else {
        std::cout << "Invalid input" << std::endl;
    }

    return 0;
}
