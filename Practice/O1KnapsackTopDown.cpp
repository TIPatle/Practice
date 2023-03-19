#include <iostream>
#include <vector>

using namespace std;



int main(){

    int n;
    cin>>n;

    vector <pair<int, int>> v(n+1);

    for ( int i = 0; i<n; i++ )
        cin>>v[i].first>>v[i].second;

    int w;
    cin>>w;

    int dp[n+1][w+1];

    for ( int i = 0; i<=n; i++ ){

        for ( int j = 0; j<=w; j++ ){

            if ( i == 0 || j == 0 ){

                dp[i][j] = 0;
                continue;

            }

            if ( v[i].first <= j )
                dp[i][j] = max(v[i].second + dp[i-1][j-v[i].first], dp[i-1][j]);

            else
                dp[i][j] = dp[i-1][j];

        }

    }

    cout<<dp[n][w]<<endl;

    return 0;

}