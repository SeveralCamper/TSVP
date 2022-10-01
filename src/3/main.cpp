#include "third_lab.h"

int main() {
    int size = 0;
    std::cout << "\033c";
    std::cout << "Please, enter the size of the array: ";
    std::cin >> size;
    if (size < 0) {
        throw std::runtime_error("Error: Input size is less ther one");
    }
    std::complex<double> *complex_array = new std::complex<double>[size];
    if (complex_array == nullptr) {
        throw std::runtime_error("Error: Bad memory alloc");
    }

    int iter = 0;
    double real_part = 0, imaginary_part = 0;
    std::ifstream file("data.txt");
    while (file >> real_part >> imaginary_part && iter < size) {
        std::complex<double> new_complex(real_part, imaginary_part);
        complex_array[iter] = new_complex;
        iter++;
    }
    file.close();
    std::cout << "\033c";
    print_complex_array(complex_array, size);

    std::complex<double> *dft_array = new std::complex<double>[size];
    if (dft_array == nullptr) {
        throw std::runtime_error("Error: Bad memory alloc");
    }

    dft_array = discrete_fourier_transform(complex_array, size);
    std::cout << "Discrete Fourier Transform" << std::endl;
    print_complex_array(dft_array, size);

    std::complex<double> *sfft_array = new std::complex<double>[size];
    if (sfft_array == nullptr) {
        throw std::runtime_error("Error: Bad memory alloc");
    }

    sfft_array = semi_fast_fourier_transform(complex_array, 4, 2);
    std::cout << "Semi Fast Fourier Transform" << std::endl;
    print_complex_array(sfft_array, size);

    std::complex<double> *rev_sfft_array = new std::complex<double>[size];
    if (rev_sfft_array == nullptr) {
        throw std::runtime_error("Error: Bad memory alloc");
    }
    std::cout << std::endl;

    rev_sfft_array = reverse_semi_fast_fourier_transform(sfft_array, 4, 2);
    std::cout << "Reversed Semi Fast Fourier Transform" << std::endl;
    print_complex_array(rev_sfft_array, size);

    return 0;
}
