#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    cin>>n;

    vector <int> arr(n+1);
    for ( int i = 0; i<n; i++ )
        cin>>arr[i];

    int k;
    cin>>k;

    int dp[n+1][k+1];

    for ( int i = 0; i<=n; i++ ){

        for ( int j = 0; j<=k; j++ ){

            if ( i == 0 )
                dp[i][j] = 0;

            if ( j == 0 )
                dp[i][j] = 1;

            if ( arr[i] <= j && i > 0)
                dp[i][j] = dp[i-1][j-arr[i]] | dp[i-1][j];

            else if ( arr[i] > j && i > 0)
                dp[i][j] = dp[i-1][j];

        }

    }

    cout<<dp[n][k]<<endl;

    return 0;

}