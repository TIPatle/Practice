// Find the xor of between l to r 
// Basically we calculate xor(l-1) and xor(r) and taking xor of both to cancel duplicate
// l = 3 r = 5 
// xor(2) = 1^2
// xor(5) = 1^2^3^4^5
// ans = xor(2) ^ xor(5) = (1^2)^(1^2^3^4^5)
#include <iostream>

using namespace std;

int numxor( int n ){

    if ( n % 4 == 0 )
        return n;

    else if ( n % 4 == 1 )
        return 1;

    else if ( n % 4 == 2 )
        return n + 1;

    return 0;

}

int main(){

    int l, r;
    cin>>l>>r;

    cout<<(numxor(l-1) ^ numxor(r))<<endl;
    
    return 0;

}