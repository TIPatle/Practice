#include <iostream>

using namespace std;

int coinsWays( int coins[], int n, int k ) {

    if ( k == 0 )
        return 1;

    if ( n == 0 )
        return 0;

    if ( k >= coins[n-1] )
        return coinsWays(coins, n, k-coins[n-1]) + coinsWays(coins, n - 1, k);

    return coinsWays(coins, n-1, k);

}

int main(){

    int n;
    cin>>n;

    int coins[n];
    for ( int i = 0; i<n; i++ )
        cin>>coins[i];

    int k;
    cin>>k;

    cout<<coinsWays(coins, n, k)<<endl;

    return 0;

}