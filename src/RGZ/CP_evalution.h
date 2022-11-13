#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#include "matrix.h"

//  Computing performance evaluation

void CPE_check(int matrix_size, int operation_amount);

double time_start();
double time_stop();
