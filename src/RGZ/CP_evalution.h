#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include "matrix.h"

//  Computing performance evaluation

//  gettimeofday()
struct timeval time_val_1, time_val_2, data_time_val;

double *CPE_check(int rows, int cols);

double time_start();
double time_stop();


