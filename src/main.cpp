#include "first_lab.h"

int main() {
    int size = 0;
    std::cout << "Please, enter the size of the array: ";
    std::cin >> size;
    if (size < 0) {
        throw std::runtime_error("Error: Input size is less ther one");
    }
    double * array = new double[size];
    if (array == nullptr) {
        throw std::runtime_error("Error: Bad memory alloc");
    }
    
}