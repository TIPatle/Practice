#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp(1000, vector<int> (1000, -1));
int maxProfit( int length[], int price[], int n, int k ){

    if ( k == 0 || n == 0 ) 
        return 0;

    if ( dp[n][k] != -1 )
        return dp[n][k];

    if ( k >= length[n-1])
        return dp[n][k] = max(maxProfit(length, price, n-1, k), price[n-1] + maxProfit(length, price, n, k-length[n-1]));

    return dp[n][k] = maxProfit(length, price, n-1, k);

}

int main(){

    int n;
    cin>>n;

    int length[n];
    int price[n];

    for ( int i = 0; i<n; i++ )
        cin>>length[i]>>price[i];

    int k;
    cin>>k;

    cout<<maxProfit(length, price, n, k);

    return 0;

}