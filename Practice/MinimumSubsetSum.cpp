#include <iostream>
#include <climits>

using namespace std;

bool SubsetSum(int arr[], int n, int k){

    bool dp[n+1][k+1];

    for ( int i = 0; i<=n; i++ ){

        for ( int j = 0; j<=k; j++){

            if ( i == 0 )
                dp[i][j] = 0;

            if ( j == 0 )
                dp[i][j] = 1;

            if ( i > 0 ){

                if ( j >= arr[i-1] )
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];

                else 
                    dp[i][j] = dp[i-1][j];

            }

        }

    }

    return dp[n][k];

}

int main(){

    int n;
    cin>>n;
    
    int arr[n];
    for ( int i = 0; i<n; i++ )
        cin>>arr[i];

    int sum = 0;
    for ( int i = 0; i<n; i++ )
        sum += arr[i];

    int num = 0;
    for ( int i = 0; i<= (sum / 2); i++ ){

        if ( SubsetSum(arr, n, i))
            num = i;

    }
    
    cout<<sum - 2 * num<<endl;
    
    return 0;

}