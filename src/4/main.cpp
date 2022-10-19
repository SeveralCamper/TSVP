#include <string>
#include <iostream>
#include <climits>
using namespace std;

int main() {
    std::string a,n;
    long long *A, *B, *C, length, l,cc;
    std::cin >> a;
    std::cin >> n;
    A = new long long [a.size()];
    B = new long long [n.size()];

    for (int i = 0; i < a.size(); i++)
    
        A[i] = a[a.size() - i - 1] - '0';
        
    for (int i = 0; i < n.size(); i++)
        B[i] = n[n.size() - i - 1] - '0';

    length = a.size() + n.size() - 1 ;
    l = length;
    C = new long long [length];
    for (int ix = 0; ix < length; ix++) {
        C[ix] = 0;
    }

    for (int ix = 0; ix < a.size(); ix++) {
        for (int jx = 0; jx < n.size(); jx++) {
            C[ix + jx] += A[ix] * B[jx];
          
        }
    }

    for (int ix = 0; ix < length-1; ix++) {
        C[ix + 1] +=  C[ix] / 10;
        C[ix] %= 10;

    }

    while (C[length] == 0)
        length-- ;
    for(int i=length; i>-1; i--) {
        cout<<C[i];
    }
    std::cout << std::endl;

    return 0;

}