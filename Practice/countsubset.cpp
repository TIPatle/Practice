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

int countset( int arr[], int sum, int n){

    if ( sum == 0 )
        return 1;

    if ( n == 0 )
        return 0;

    if ( sum >= arr[n-1] )
        return( countset(arr, sum-arr[n-1], n-1) + countset(arr, sum, n-1));

    return countset(arr, sum, n-1);

}

int countop( int arr[], int sum, int n){

    int t[n+1][sum+1];

    for ( int i = 0; i<=sum; i++ )
        t[0][i] = 0;

    for ( int i = 0; i<n; i++ )
        t[i][0] = 1;

    for ( int i = 1; i<=n; i++ ){

        for ( int j = 1; j<=sum; j++ ){

            if ( j >= arr[i-1] )
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];

            else 
                t[i][j] = t[i-1][j];

        }

    }

    return t[n][sum];
 
}

int main(){
    
    int arr[] = {2, 3, 5, 6, 8, 10};
    int n = 6;
    int sum = 10;

    cout<<countop(arr, sum, n);

    return 0;

}