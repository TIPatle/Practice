#include <iostream>
#include <vector>

using namespace std;

long int fibCalculate ( int n ){     // O(2^n)

    if ( n == 0)
        return 0;

    if ( n == 1)
        return 1;

    return fibCalculate(n-1) + fibCalculate(n-2);

}

vector <long int> fibbonaci (1e7, -1);

long int fibo( int n ){   
    // time complexity is not greatly reduced which is O(2^n)
    // because in worst case we have to calculate all the sequence 

    if ( n == 0 )
        return fibbonaci[0] = 0;

    if ( n == 1 )
        return fibbonaci[1] = 1;

    if ( fibbonaci[n] != -1 )
        return fibbonaci[n];

    return fibbonaci[n] = fibo(n-1) +  fibo(n-2);

}

int main(){

    int n;
    cin>>n;

    cout<<fibo(n)<<endl;

    return 0;

}