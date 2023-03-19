

#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    cin>>n;

    vector <int> arr(n+1);
     
    for ( int i = 0; i<n; i++)
        cin>>arr[i];

    vector<vector<int>> dp(1e3, vector<int>(1e3, 1e5));

    for ( int i = 1; i<n; i++ )
        dp[i][i] = 0;

    for ( int i = 1; i<n; i++ ){

        for ( int j = i + 1; j<n; j++){

            for (int k = i; k<j; k++)
                dp[i][j] = min(dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j], dp[i][j]);

        }

    }

    cout<<dp[1][n-1]<<endl;

    return 0;

}