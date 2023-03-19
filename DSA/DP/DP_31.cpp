#include <iostream>
#include <vector>

using namespace std;

vector <int> arr1(1e5);
vector <int> arr2(1e5);

vector <vector<vector<int>>> dp(2001, vector<vector<int>>(2001, vector<int> (6, -1)));

int solve (int i , int j, int k ){

    if ( i < 0 || j < 0)
        return 0;

    if ( dp[i][j][k] != -1 )
        return dp[i][j][k];

    if ( arr1[i] == arr2[j] )
        return dp[i][j][k] =  1 + solve( i-1, j-1, k );

    if ( k > 0) 
        return dp[i][j][k] =  1 + solve( i-1, j-1, k - 1 );

    return dp[i][j][k] =  max ( solve (i-1, j, k), solve(i, j-1, k));

}

int main(){

    int n, m, k;
    cin>>n>>m>>k;

    for ( int i = 0; i<n; i++)
        cin>>arr1[i];

    for ( int j = 0; j<m; j++ )
        cin>>arr2[j];

    cout<<solve(n-1, m-1, k)<<endl;

    return 0;

}