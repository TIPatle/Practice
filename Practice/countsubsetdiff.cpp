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

int countsum(int arr[], int n, int sum ){

    if ( sum == 0 )
        return 1;

    if ( n == 0 )
        return 0;

    if ( sum >= arr[n-1] )
        return countsum(arr, n-1, sum-arr[n-1]) + countsum(arr, n-1, sum);

    return countsum(arr, n-1, sum);

}

vii t;

int countmemo(int arr[], int n, int sum ){

    if ( sum == 0 )
        return 1;

    if ( n == 0 )
        return 0;

    if ( t[n][sum] != -1 )
        return t[n][sum];

    if ( sum >= arr[n-1] )
        return t[n][sum] = countmemo(arr, n-1, sum-arr[n-1]) + countmemo(arr, n-1, sum);

    return t[n][sum] = countmemo(arr, n-1, sum);

}

int subtop( int arr[], int n, int sum ){

    for ( int i = 0; i<=sum; i++ )
        t[0][i] = 0;

    for ( int i = 0; i<=n; i++ )
        t[i][0] = 1;

    for ( int i = 1; i<=n; i++ ){

        for ( int j = 1; j <= sum; j++ ){

            if ( j >= arr[i-1] ){

                t[i][j] = t[i-1][j-arr[i-1] ] + t[i-1][j];

            }

            else    
                t[i][j] = t[i-1][j];

        }

    }    

    return t[n][sum];

}

int main(){
    
    int arr[] = {1, 1, 2, 3};
    int n = 4;
    int diff = 1;

    int s =0;
    for ( auto it : arr )   
        s += it;

    int sum = ( (s - diff) / 2 );
    t = vii(n+1, vi(sum+1, -1));

    cout<<subtop (arr, n, sum);


}