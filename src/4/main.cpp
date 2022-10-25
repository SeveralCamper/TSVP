#include <string>
#include <iostream>
#include <climits>
using namespace std;

int main() {
    int count = -1;
    int min_size = 0;
    std::string a, n;
    long long *A, *B, *C, length, l,cc;
    std::cin >> a;
    std::cin >> n;
    A = new long long [a.size()];
    B = new long long [n.size()];

    min_size = (int) a.size() - n.size();

    for (int i = 0; i < a.size(); i++) {
        A[i] = a[a.size() - i - 1] - '0';
    }
        
    for (int i = 0; i < n.size(); i++) {
        B[i] = n[n.size() - i - 1] - '0';
    }

    length = a.size() + n.size();
    l = length;
    C = new long long [length];
    for (int ix = 0; ix < length; ix++) {
        C[ix] = 0;
    }

    for (int ix = 0; ix < a.size(); ix++) {
        count += 1;
        for (int jx = 0; jx < n.size(); jx++) {
            count += 1;
            C[ix + jx] += A[ix] * B[jx];
        }
    }

    for (int ix = 0; ix < length-1; ix++) {
        C[ix + 1] +=  C[ix] / 10;
        C[ix] %= 10;

    }

    while (C[length] == 0) {
        length--;
    }
    for(int i = length - 1; i > -1; i--) {
        std::cout << C[i];
    }   
    count -= min_size; 
    std::cout << std::endl;
    std::cout << "Count: " << count << std::endl;

    return 0;

}