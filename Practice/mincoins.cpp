#include <bits/stdc++.h>

#define N 1e7
#define M 1e5

#define vi vector<int>
#define vii vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pii pair<int, int>

#define rep(i, a, b) for(int i = a; i<b; i++)
#define decrep(i, a, b) for ( int i = a; i>=b; i--)

using namespace std;

int coinchange( int coins[], int sum, int n){

    if ( sum == 0 )
        return 0;

    if ( n == 0 )
        return INT16_MAX;

    if ( coins[n-1] <= sum )
        return min( coinchange( coins, sum - coins[n-1], n ) + 1, coinchange(coins, sum, n-1)  );

    return coinchange(coins, sum, n-1);

}

int cointop( int coins[], int sum, int n){

    vii t(n+1, vi(sum+1, -1));

    rep(i, 0, sum+1)
        t[0][i] = N;

    rep(i, 0, n+1)
        t[i][0] = 0;

   rep(i, 1, sum+1){

        if ( i % coins[0] == 0 ){

            t[1][i] = i / coins[0]; 

        }

        else
            t[1][i] = N;

    } 

    rep(i, 1, n+1){

        rep(j, 1, sum+1){

            if ( coins[i-1] <= j )
                t[i][j] = min(t[i][j-coins[i-1]] + 1, t[i-1][j]);

            else
                t[i][j] = t[i-1][j];

        }

    }

    return t[n][sum];

}

int main(){
    
    int coins[] = {1, 2, 3};
    int sum = 5;
    int n = 3;

    cout<<cointop(coins, sum, n);

    return 0;

}