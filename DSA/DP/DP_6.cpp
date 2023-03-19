// coins change problem using memorization technique 

#include <iostream>
#include <vector>
#define N 1e3

using namespace std;

vector<vector<int>> dp(N, vector<int> (N));

int change ( vector<int> &coins, int n, int val ){

    if ( n <= 0 || val < 0)
        return 0;

    if ( val == 0 )
        return 1;

    if ( dp[n][val] != -1 )
        return dp[n][val];

    dp[n][val] = change(coins, n, val-coins[n-1]) + change(coins, n-1, val);
    
    return dp[n][val];
}

int main(){

    for ( int i = 0; i<N; i++ )
        for ( int j = 0; j<N; j++ )
            dp[i][j] = -1;

    int n;
    cin>>n;

    vector <int> coins(n);
    for ( int i = 0; i<n; i++ )
        cin>>coins[i];

    int val;
    cin>>val;

    cout<<change(coins, n, val);  

    return 0;

}