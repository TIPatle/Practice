#include <iostream>

using namespace std;

int main(){

    int n;
    cin>>n;

    int length[n];
    int price[n];

    for ( int i = 0; i<n; i++ )
        cin>>length[i]>>price[i];


    int k;
    cin>>k;

    int dp[n+1][k+1];

    for ( int i = 0; i<=n; i++ ){

        for ( int j = 0; j<= k; j++ ){

            if ( i == 0 || j == 0 ){

                dp[i][j] = 0;
                continue;

            }

            if ( j >= length[i - 1] )
                dp[i][j] = max( dp[i][j-length[i - 1]] + price[i-1], dp[i-1][j]);

            else 
                dp[i][j] = dp[i-1][j]; 

        }

    }

    cout<<dp[n][k]<<endl;

}