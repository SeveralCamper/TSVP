#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define SIZE 7
// #define SIZE 6
int main() {
  int d[SIZE];     
  int v[SIZE];       
  int temp, minindex, min;
  int begin_index = 1;

   /* int a[SIZE][SIZE] = {
              {0,	1,	6,	2,	0,	0},
              {0,	0,	4,	0,	2,	0},
              {0,	0,	0,	0,	0,	3},
              {0,	0,	0,	0,	5,	0},
              {0,	0,	0,	0,	0,	4 },
              {0,	0,	0,	0,	0,	0},
  }; */

int a[SIZE][SIZE] = {
  {0, 3, 4, 3, 0, 0, 0},
  {3, 0, 1, 0, 0, 0, 2},
  {4, 1, 0, 2, 1, 0, 1},
  {3, 0, 2, 0, 2, 4, 0},
  {0, 0, 1, 2, 0, 1, 3},
  {0, 0, 0, 4, 1, 0,6},
  {0, 2, 1, 0, 3, 6,0}
};

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++)
      printf("%5d ", a[i][j]);
    printf("\n");
  }


  
  for (int i = 0; i < SIZE; i++) {
    d[i] = 10000;
    v[i] = 1;
  }
  d[begin_index] = 0;

  do {
    minindex = 10000;
    min = 10000;
    for (int i = 0; i < SIZE;i++) 
    { 
      if ((v[i] == 1) && (d[i] < min)) { 
        min = d[i];
        minindex = i;
      }
    }

    if (minindex != 10000) {
      for (int i = 0; i < SIZE; i++) {
        if (a[minindex][i] > 0) {
          temp = min + a[minindex][i];
          if (temp < d[i]) {
            d[i] = temp;
          }
        }
      }
      v[minindex] = 0;
    }
  } while (minindex < 10000);

  
  for (int i = 0; i < SIZE; i++){
    
   std::cout<<std::endl<<begin_index+1<<"->"<<i+1<<"="<<d[i];
  }


  int ver[SIZE]; 
  // int end = 5; 
  int end = 6;

  ver[0] = end + 1; 
  int k = 1;          
  int weight = d[end];

  while (end != begin_index) 
  {
    for (int i = 0; i < SIZE; i++) 
      if (a[i][end] != 0)          
      {
        int temp =  weight - a[i][end]; 
        if (temp == d[i]) 
        { 
          weight = temp; 
          end = i; 
          ver[k] = i + 1; 
          k++;
        }
      }
  }

  printf("\nВывод кратчайшего пути\n");
  for (int i = k - 1; i >= 0; i--) {
    printf("%3d ", ver[i]);
  }
  printf("\n");

  return 0;
}