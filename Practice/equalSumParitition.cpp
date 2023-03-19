#include <iostream>

using namespace std;

bool partitionsum(int arr[], int n, int k1, int k2){ // Take too much complexity 

    if (k1 == k2 )
        return 1;

    if ( n == 1 )
        return 0;

    return partitionsum( arr, n-1, k1, k2 + arr[n-1] ) | partitionsum(arr, n-1, k1 + arr[n-1] , k2);


}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for ( int i = 0; i<n; i++ )
        cin>>arr[i];

    cout<<partitionsum(arr, n, arr[0], 0);

    return 0;
    
}