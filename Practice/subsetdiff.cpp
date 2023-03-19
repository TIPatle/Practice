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

int subdiff ( int arr[], int range, int s1, int sum, int n){

    if ( n == 0 )
        return range - 2*s1;

    if ( sum >= arr[n-1] )
        return min(subdiff(arr, range, s1+arr[n-1], sum - arr[n-1], n-1 ),
                   subdiff(arr, range, s1, sum, n-1));

    return subdiff(arr, range, s1, sum, n-1);

}

int subsetop(int arr[], int range, int n){

    int t[n+1][range+1];

    for ( int i = 0; i<=range; i++ )
        t[0][i] = 0;

    for ( int i = 0; i<=n; i++ )
        t[i][0] = 1;

    for ( int i = 1; i<=n; i++ ){

        for ( int j = 1; j<=n; j++ ){

            if ( arr[n-1] >= j )
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];

            else 
                t[i][j] = t[i-1][j];

        }

    }

    int ans = N;

    for ( int i = 0; i<=n; i++ ){

        for ( int j = 0; j<=range; j++ ){

            if ( t[i][j] )
                ans = min(abs(range - 2*j), ans);

        }

    }

    return ans;

}

int main(){
    
    int arr[] = {1, 10, 11, 5};
    int n = 4;
    
    int range = 0;
    for ( auto it : arr )
        range += it;

    cout<<subsetop(arr, range, n);

    return 0;

}