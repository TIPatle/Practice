// Longest subsequence using DP memorization

#include <iostream>
#include <vector>

using namespace std;

vector<int> dp(1000, -1);

int maxsubsequence( vector <int> &arr, int start, int end, int previous ){

    if ( start >= end )
        return 0;

    if ( dp[start] != -1 )
        return dp[start];

    if ( arr[start] < previous )
        return maxsubsequence(arr, start+1, end, previous);

    return dp[start] = max(maxsubsequence(arr, start+1, end, previous), maxsubsequence(arr, start+1, end, arr[start]) + 1);

}

int main(){

    int n;
    cin>>n;

    vector<int> arr(n);

    for ( int i = 0; i<n; i++ )
        cin>>arr[i];

    cout<<maxsubsequence( arr, 0, n, 0 )<<endl;

    return 0;

}
