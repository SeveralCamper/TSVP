#include "first_hw.h"

int main() {
    int size = 10;
    std::cout << "\033c";
    std::cout << "Test resault for n = 10:" << std::endl << std::endl;

    asymptotic_sort_growth_func(size);

    std::cout << std::endl;
    std::cout << "Test resault for n = 100:" << std::endl;

    asymptotic_sort_growth_func(size * 10);

    std::cout << std::endl;
    std::cout << "Test resault for n = 1000:" << std::endl;

    asymptotic_sort_growth_func(size * 100);

    return 0;
}
