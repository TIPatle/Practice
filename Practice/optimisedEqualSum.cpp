#include <iostream>

using namespace std;

bool subsetSum( int arr[], int n, int sum ){

    if ( sum == 0 )
        return 1;

    if ( n == 0 )
        return 0;

    if ( sum >= arr[n-1])
       return subsetSum ( arr, n-1, sum - arr[n-1]) | subsetSum(arr, n-1, sum);

    return subsetSum(arr, n-1, sum);

}

bool partitionsum( int arr[], int n){

    int sum = 0;
    for ( int i = 0; i<n; i++ )
        sum += arr[i];

    if ( sum%2 != 0 )   
        return 0;

    return subsetSum(arr, n, sum/2);

}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for ( int i = 0; i<n; i++ )
        cin>>arr[i];

    cout<<partitionsum(arr, n);

    return 0;

}