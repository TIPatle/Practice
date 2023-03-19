#include <iostream>

using namespace std;

int main(){

    int n;
    cin>>n;

    long long dp[n+1];

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for ( int i = 3; i<=n; i++ )
        dp[i] = i * dp[i-1];

    cout<<dp[n]<<endl;
    
    return 0;

}