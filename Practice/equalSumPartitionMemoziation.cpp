#include <iostream>

using namespace std;

int dp[100][100] = {-1};

bool partitionsum(int arr[], int n, int k1, int k2){

    if ( k1 == k2 )
        return 1;

    if ( n == 1)
        return 0;


    if ( dp[n][k1])
        return dp[n][k1];

    bool a1 = partitionsum(arr, n-1, k1, k2 + arr[n-1] );
    bool a2 = partitionsum(arr, n-1, k1 + arr[n-1], k2 );

    if ( a1 | a2 )
        return dp[n][k1] = 1;

    return dp[n][k1] = 0;

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