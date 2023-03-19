#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){

    vector <int> dp(1e7, 1e7);

    int n;
    cin>>n;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for ( int i = 1; i*i <=n; i++ ){

        for ( int j = 0; i*i+j <= n; j++ ){

            dp[i*i+j] = min(dp[i*i+j], 1+dp[j]);

        }

    }

    cout<<dp[n]<<endl;

    return 0;

}