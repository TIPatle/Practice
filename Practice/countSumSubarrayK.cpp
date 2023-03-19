#include <iostream>

using namespace std;

int subsetK( int arr[], int n, int k ){

    if ( k == 0 )
        return 1;
    
    if ( n == 0 )   
        return 0;

    if ( k >= arr[n-1] )
        return subsetK(arr, n-1, k-arr[n-1]) + subsetK(arr, n-1, k);

    return subsetK(arr, n-1, k);

}

int main(){

    int n;
    cin>>n;

    int arr[n];

    for ( int i = 0; i<n; i++ )
        cin>>arr[i];

    int k;
    cin>>k;

    cout<<subsetK(arr, n, k);

    return 0;

}