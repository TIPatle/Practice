// print xor of all number between 1 to n
#include <iostream>

using namespace std;

int main(){

    int num; 
    cin>>num;

    if ( num % 4 == 0 )
        cout<<num<<endl;

    else if ( num % 4 == 1 )
        cout<<1<<endl;

    else if ( num % 4 == 2 )
        cout<<num + 1<<endl;

    else
        cout<<0<<endl;

    return 0;

}