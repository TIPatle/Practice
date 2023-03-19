#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int> coins(n);
    for ( int i = 0; i<n; i++)
        cin>>coins[i];

    int val;
    cin>>val;

    vector<vector<int>> dp(n+1, vector<int> (val+1, 0));
    dp[0][0] = 1;

    for ( int i = 1; i<=n; i++ ){

        for ( int j = 0; j<=val; j++ ){

            if ( j-coins[i-1] >= 0 ){

                dp[i][j] += dp[i][j-coins[i-1]];

            }

            dp[i][j] += dp[i-1][j];

        }

    }

    cout<<dp[n][val]<<endl;

    return 0;
}
