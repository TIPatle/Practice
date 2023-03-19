#include <iostream>

using namespace std;

int main(){

    string a, b;
    cin>>a>>b;

    int n = a.length(), m = b.length();
    int dp[n+1][m+1];

    for ( int i = 0; i<= n; i++ ){

        for ( int j = 0; j<=m; j++ ){

            if ( i == 0 || j == 0 ){

                dp[i][j] = 0;
                continue;

            }

            if ( a[i-1] == b[j-1] )
                dp[i][j] = 1 + dp[i-1][j-1];

            else 
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

        }

    }

    cout<<dp[n][m]<<endl;

    return 0;

}