#include "second_lab.h"

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

    /* std::complex<double> *fft_array = new std::complex<double>[size];
    if (fft_array == nullptr) {
        throw std::runtime_error("Error: Bad memory alloc");
    }

    fft_array = fast_fourier_transform(complex_array);
    std::cout << Fast Fourier Transform << std::endl;
    print_complex_array(fft_array, size);

    std::complex<double> *rev_fft_array = new std::complex<double>[size];
    if (rev_fft_array == nullptr) {
        throw std::runtime_error("Error: Bad memory alloc");
    }

    rev_fft_array = reverse_fast_fourier_transform(complex_array);
    std::cout << Reversed Fast Fourier Transform << std::endl;
    print_complex_array(rev_fft_array, size); */

    return 0;
}
