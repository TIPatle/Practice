#include <iostream>
#include <climits>
#define M int(1e7)
using namespace std;

int dp[M];

int minsquare( int n ){  // O(2^n)

    if ( n == 0 || n == 1 || n == 2 || n == 3 )
        return n;

    int ans = INT_MAX;
    for ( int i = 1; i*i <= n; i++ ){

        ans = min(ans, 1 + minsquare(n - (i*i)) );

    }

    return ans;

}

int minisqari ( int n ){ 
    // takes less time than expected O(2^n) as some of the calculated before but not O(n)

    if ( n == 0 || n == 1 || n == 2 || n == 3 )
        return dp[n] = n;

    if (dp[n] != M )
        return dp[n];

    for ( int i = 1; i*i <= n; i++ ){

        dp[n] = min(dp[n], 1 + minisqari(n - (i*i)) );

    }

    return dp[n];

}

int main(){

    for ( int i = 0; i<M; i++ )
        dp[i] = M;

    int n;
    cin>>n;

    cout<<minisqari(n)<<endl;

    return 0;

}