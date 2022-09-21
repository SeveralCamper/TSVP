#include "first_lab.h"

int main() {
    int size = 0;
    std::cout << "\033c";
    std::cout << "Please, enter the size of the array: ";
    std::cin >> size;
    if (size < 0) {
        throw std::runtime_error("Error: Input size is less ther one");
    }
    double * array = new double[size];
    if (array == nullptr) {
        throw std::runtime_error("Error: Bad memory alloc");
    }
    std::cout << "\033c";
    std::cout << "How you want to fill the array?" << std::endl;
    std::cout << "1. Fill inc." << std::endl << "2. Fill dec." << std::endl << "3. Fill rand." << std::endl;
    std::cout << "4. Fill in manually." << std::endl << "5. Exit." << std::endl;
    int choice;
    std::cin >> choice;
    if (choice < 1 || choice > 5) {
        throw std::runtime_error("Error: Invalid input. Choose an correct option: from 1 to 5");
    }
    switch (choice) {
        case 1:
            std::cout << "\033c";
            fill_inc(array, size);
            std::cout << "Your array:" << std::endl;
            print_array(array, size);
            break;
        case 2:
            std::cout << "\033c";
            fill_dec(array, size);
            std::cout << "Your array:" << std::endl;
            print_array(array, size);
            break;
        case 3:
            std::cout << "\033c";
            fill_rand(array, size, 0, 100);
            std::cout << "Your array:" << std::endl;
            print_array(array, size);
            break;
        case 4:
            std::cout << "\033c";
            for (int i = 0; i < size; i++) {
                std::cout << "\033c";
                std::cout << "Please, enter array[" << i << "]: ";
                std::cin >> array[i];
            }
            std::cout << "Your array:" << std::endl;
            print_array(array, size);
            break;
        case 5:
            std::cout << "\033c";
            return 0;
            break;
    }
    choice = -1;

    std::cout << "How you want to sort array?" << std::endl;
    std::cout << "1. Bubble Sort." << std::endl << "2. Select Sort." << std::endl;
    std::cout << "3. Merge Sort(Modified)." << std::endl << "4. Exit." << std::endl;
    std::cin >> choice;
    if (choice < 1 || choice > 4) {
        throw std::runtime_error("Error: Invalid input. Choose an correct option: from 1 to 4");
    }
    switch (choice) {
        case 1:
            std::cout << "\033c";
            bubble_sort(array, size);
            std::cout << "Your array:" << std::endl;
            print_array(array, size);
            break;
        case 2:
            std::cout << "\033c";
            select_sort(array, size);
            std::cout << "Your array:" << std::endl;
            print_array(array, size);
            break;
        case 3:
            std::cout << "\033c";
            merge_sort(array, size);
            std::cout << "Your array:" << std::endl;
            print_array(array, size);
            break;
        case 4:
            std::cout << "\033c";
            return 0;
            break;
    }

    return 0;
}
