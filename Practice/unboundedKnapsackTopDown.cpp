#include <iostream>

using namespace std;

int main(){

    int n;
    cin>>n;

    int val[n];
    int wt[n];
    for ( int i = 0; i<n; i++ )
        cin>>wt[i]>>val[i];

    int k;
    cin>>k;

    int dp[n+1][k+1];

    for ( int i = 0; i<=n; i++ ){

        for ( int j = 0; j<=k; j++ ){

            if ( i == 0 || j == 0 ){

                dp[i][j] = 0;
                continue;

            }

            if ( j >= wt[i-1] )
                dp[i][j] = max( dp[i][j-wt[i-1]] + val[i-1], dp[i-1][j]);

            else 
                dp[i][j] = dp[i-1][j];

        }

    }

    cout<<dp[n][k]<<endl;

    return 0;

}