#include <iostream>

using namespace std;

int gcdd( int a, int b ){

    if ( a == 0 )
        return b;

    return gcdd(b%a, a);

}

int main(){

    int a, b;
    cin>>a>>b;

    cout<<gcdd(a, b)<<endl;

}