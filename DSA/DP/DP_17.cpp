// Matrix chain multiplicaion - minimum no of operation to compute the multiplication of matrix
// Using DP memorization

#include <iostream>
#include <vector>

using namespace std;

vector<int> arr(1e5);
vector<vector<int>> dp(1e3, vector<int> (1e3, 1e5));

int mcm(int i, int j){   // Reducing time complexity by avoiding the overlapping subproblem by storing ans in array

    if ( i == j )
        return 0;

    if ( dp[i][j] != 1e5 )
        return dp[i][j];

    for (int k = i; k<j; k++)
        dp[i][j] = min(mcm(i, k) + mcm(k+1, j) + arr[i-1]*arr[k]*arr[j], dp[i][j]);

    return dp[i][j];

}

int main(){

    int n;
    cin>>n;

    for ( int i = 0; i<n; i++ )
        cin>>arr[i];

    cout<<mcm(1, n-1);


    return 0;

}