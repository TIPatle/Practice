// Xor of all subset 
// Example : {1, 2, 3}
// All subsets are :
// {}, {1}, {2}, {3}, {1, 2}, {2, 3}, {1, 3}, {1, 2, 3}
// xor = {1}^{2}^{3}^{1^2}^{2^3}^{1^3}^ {1^2^3} = 0
// Edge case will be when set of size 1

#include <iostream>

using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];
    for ( int i = 0; i<n; i++ )
        cin>>arr[i];

    if ( n == 1)
        cout<<arr[0]<<endl;
    
    else 
        cout<<0<<endl;

    return 0;

}