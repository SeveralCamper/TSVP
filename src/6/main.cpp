#include <iostream>
#include <cmath>
using namespace std;
#define N 4
#define K 2

int main() {
    long int Array[N/K] = {10,99};
    long int Array2[N/K] = {10,99};  
    long int temp = 0, cnt = 0;

    for(int j = 0; j < 1; j++)  {
        temp+= ((Array[j]*Array2[j])*pow(10,N)+((Array[j]+Array[j+1])*
        (Array2[j]+Array2[j+1])-(Array[j]*Array2[j])-(Array[j+1]*
        Array2[j+1]))*pow(10,K)+(Array[j+1]*Array2[j+1]));
    }

    if (Array[0] % 10 == 0 && Array[1] % 10 == 0) {
        cnt = 1;
    } else {
        cnt += 10 + N + K;
    }
    std::cout << temp << std::endl;
    std::cout << "Operation type: "<< cnt << std::endl;

    return 0;
}