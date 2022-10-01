#include "first_hw.h"

void func_bubble_sort(func_t *func_arr, int array_length) {
  for (int i = 0; i < array_length - 1; i++) {
    for (int j = 0; j < array_length - i - 1; j++) {
      if (func_arr[j].data > func_arr[j + 1].data) {
        std::swap(func_arr[j].data, func_arr[j + 1].data);
      }
    }
  }

  for (int i = 0; i < 9; i++) {
    check_func(func_arr[i].num);
  }

  /* std::cout << std::endl;
  for (int i = 0; i < 9; i++) {
    std::cout << "Function resault: " << func_arr[i].data << std::endl;
  } */
}

double factorial(double number) {
    if (number <= 1) {
        return 1;
    } else {
        return number * factorial(number - 1);
    }
}

void check_func(int i) {
    switch (i) {
        case 0:
            std::cout << "(1.5)^n" << std::endl;
            break;
        case 1:
            std::cout << "n^3" << std::endl;
            break;
        case 2:
            std::cout << "n^2 * log2(n)" << std::endl;
            break;
        case 3:
            std::cout << "3^(log2(n))" << std::endl;
            break;
        case 4:
            std::cout << "10^(log2(n))" << std::endl;
            break;
        case 5:
            std::cout << "!n" << std::endl;
            break;
        case 6:
            std::cout << "2^(sqrt(n))" << std::endl;
            break;
        case 7:
            std::cout << "2^(2^n)" << std::endl;
            break;
        case 8:
            std::cout << "3^(n^2)" << std::endl;
            break;
        default:
        std::cout << "There is no more functions!" << std::endl;
            break;
    }
}

void asymptotic_sort_growth_func(int n) {
    func_t *func_arr_res = new func_t[9];
    func_arr_res[0].data = pow(1.5, n);
    func_arr_res[0].num = 0;
    func_arr_res[1].data = pow(n, 3);
    func_arr_res[1].num = 1;
    func_arr_res[2].data = pow(n, 2) * log2(n);
    func_arr_res[2].num = 2;
    func_arr_res[3].data = pow(3, log2(n));
    func_arr_res[3].num = 3;
    func_arr_res[4].data = pow(10, log2(n));
    func_arr_res[4].num = 4;
    func_arr_res[5].data = factorial(n);
    func_arr_res[5].num = 5;
    func_arr_res[6].data = pow(2, sqrt(n));
    func_arr_res[6].num = 6;
    func_arr_res[7].data = pow(2, pow(2, n));
    func_arr_res[7].num = 7;
    func_arr_res[8].data = pow(3, pow(n, 2));
    func_arr_res[8].num = 8;

    func_bubble_sort(func_arr_res, 9);

    free(func_arr_res);
}
