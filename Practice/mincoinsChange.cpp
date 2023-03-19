#include <iostream>
#include <climits>

using namespace std;

int main(){

    int n;
    cin>>n;

    int coins[n];
    for ( int i = 0; i<n; i++ )
        cin>>coins[i];

    int k;
    cin>>k;

    int dp[n+1][k+1];
    for ( int i = 0; i<=n; i++ ){

        for ( int j = 0; j<=k; j++ ){

            if ( i == 0 )
                dp[i][j] = INT_MAX;

            if ( j == 0 )
                dp[i][j] = 0;

            if ( i > 0 ){

                if ( j % coins[i-1] == 0 )
                    dp[i][j] = j / coins[i-1];

                else 
                    dp[i][j] = INT_MAX - 5;

                if ( j >= coins[i-1] )
                    dp[i][j] = min( 1 + dp[i][j - coins[i-1]], min(dp[i-1][j], dp[i][j]));

                else 
                    dp[i][j] =  min(dp[i-1][j], dp[i][j]);


            }


        }



    }

    cout<<dp[n][k]<<endl;

    return 0;

}