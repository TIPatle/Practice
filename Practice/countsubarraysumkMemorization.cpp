#include <iostream>
#include <vector>

using namespace std;

vector <vector<int>> dp(100, vector<int> (100, -1));

int subsetcount( int arr[], int n, int k){

    if ( k == 0 )
        return 1;

    if ( n == 0 )
        return 0;

    if ( dp[n][k] != -1  )
        return dp[n][k];

    if ( k >= arr[n-1])
        dp[n][k] = subsetcount(arr, n-1, k-arr[n-1]) + subsetcount(arr, n-1, k);

    else 
        dp[n][k] = subsetcount(arr, n-1, k);

    return dp[n][k];

}

int main(){

    int n;
    cin>>n;

    int arr[n];

    for ( int i = 0; i<n; i++ ) 
        cin>>arr[i];

    int k;
    cin>>k;

    cout<<subsetcount( arr, n, k);

    return 0;

}