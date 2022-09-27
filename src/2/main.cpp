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
    iter = 0;
    std::cout << "\033c";

    std::cout << "Your complex array:" << std::endl;
    while (iter < size) {
        std::cout << complex_array[iter] << std::endl;
        iter++;
    }

    return 0;
}
