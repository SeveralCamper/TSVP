#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <fstream>
#include <iostream>

typedef struct func {
    int num;
    double data;
} func_t;

double factorial(double number);

void check_func(int i);
void asymptotic_sort_growth_func(int n);

void func_bubble_sort(func_t *func_arr, int array_length);

