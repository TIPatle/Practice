#include <iostream>

// we can use fibonnaci series to calculate the ans if we observe more it is just a fibonnaci series


using namespace std;

int main(){

    int n;
    cin>>n;

    int zero[n] ={0};
    int one [n] = {0};

    zero[1] = 1;
    one[1] = 1;

    for ( int i = 2; i<=n; i++){

        if ( one[i-1] >= 1 )
            one[i] = zero[i-1];  
        
        zero[i] = zero[i-1] + one[i-1];

    }

    cout << one[n]  + zero[n]<<endl;

    return 0;

}