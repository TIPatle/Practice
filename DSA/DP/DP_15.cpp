#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp(1e3, vector<int> (1e3, -1));

int main(){

    string s1, s2;
    cin>>s1>> s2;

    int n =  s1.size();
    int m = s2.size();

    for ( int i = 0; i<=n; i++ ){

        for ( int j = 0; j<=m; j++ ){

            if ( i == 0 || j == 0 ){

                dp[i][j] = 0;
                continue;
                
            }

            if ( s1[i] == s2[j] )
                dp[i][j] = 1+ dp[i-1][j-1];

            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

        }

    }


    cout<<dp[n][m]<<endl;

    return 0;

}