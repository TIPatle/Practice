// find the power of the any number 

#include <iostream>

using namespace std;

long int power( int n, int p ){

    long int ans = 1;
    while ( p ){

        if ( p & 1 )
            ans *= n;

        n *= n;
        p = p >> 1;

    }

    return ans;

}

int main(){

    int n, p;
    cin>>n>>p;

    cout<<power(n, p)<<endl;

    return 0;

}