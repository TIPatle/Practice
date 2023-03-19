#include <iostream>

using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n+1];
    for ( int i = 1; i<=n; i++ )
        cin>>arr[i];

    int sum = 0; 
    for ( int i = 1; i<=n; i++ ) 
        sum += arr[i];

    if ( sum % 2 != 0 ){

        cout<<false<<endl;
        return 0;

    }

    int k = sum / 2;

    bool dp[n+1][k + 1] = {0};

    for ( int i = 0; i<=n; i++ ){

        for ( int j = 0; j<=k; j++ ){

            if ( i == 0 && j == 0 ){

                dp[i][j] = 1;
                continue;

            }

            if ( i == 0 ){

                dp[i][j] = 0;
                continue;

            }

            if ( j == 0 ){

                dp[i][j] = 1;
                continue;

            }

            if ( j >= arr[i])
                dp[i][j] = dp[i-1][j-arr[i]] || dp[i-1][j];

            
            else if ( j < arr[i] )  
                dp[i][j] = dp[i-1][j];

        }

    }

    cout<<dp[n][k]<<endl;

    return 0;

}