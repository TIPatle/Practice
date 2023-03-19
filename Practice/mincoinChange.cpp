#include <iostream>

using namespace std;

int minCoins( int coins[], int n, int k ){

    if ( k % coins[n-1] == 0 )
        return k / coins[n-1];

    if ( k == 0 )
        return 0;
    
    if ( n == 0 )
        return INT32_MAX - 5;
    
    if ( k >= coins[n-1] )
        return min( 1 + minCoins(coins, n, k-coins[n-1]), minCoins(coins, n-1, k) );

    return minCoins(coins, n-1, k);

}

int main(){

    int n;
    cin>>n;

    int coins[n];
    for ( int i = 0; i<n; i++ )
        cin>>coins[i];

    int k;
    cin>>k;

    cout<<minCoins(coins, n, k)<<endl;

    return 0;

}