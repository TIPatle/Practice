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

bool subsetSum( int arr[], int n, int sum){

    if ( sum == 0 )
        return true;

    if ( n == 0 )
        return false;

    if ( arr[n-1] <= sum  )
        return subsetSum(arr, n-1, sum-arr[n-1]) || subsetSum(arr, n-1, sum);

    return subsetSum(arr, n-1, sum);

}

vii t;

bool subsetmemo(int arr[], int n, int sum ){

    if ( sum == 0 )
        return true;

    if ( n == 0 )
        return false;

    if ( t[n][sum] != -1 )
        return t[n][sum];

    if ( arr[n-1] <= sum  )
        return t[n][sum] = subsetSum(arr, n-1, sum-arr[n-1]) || subsetSum(arr, n-1, sum);

    return t[n][sum] = subsetSum(arr, n-1, sum);

}

bool subsetop(int arr[], int n, int sum){

    for ( int i = 0; i<sum; i++ )
        t[0][i] = 0;   

    for ( int i = 0; i<n; i++ )
        t[i][0] = 1;

    for ( int i = 1; i<=n; i++ ){

        for ( int j = 1; j<= sum; j++ ){

            if ( arr[i-1] <= j )
                t[i][j] = t[i-1][j] || t[i-1][j-1];

            else 
                t[i][j] = t[i-1][j];

        }

    }

    return t[n][sum];

}

int main(){
    
    int arr[] = {2, 3, 7, 8, 10};
    int sum = 11;

    t = vii(5+1, vi(sum+1,-1));
    cout<<subsetop (arr, 5, sum);

    return 0;

}