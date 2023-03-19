// Longest Common Subsequence using DP using memorization 

#include <iostream>
#include <vector>

using namespace std;

vector <vector<int>> dp(1e3, vector<int> (1e3, -1));

int LCS( string &s1, string &s2, int n, int m ){

    if( n <= 0 || m <= 0)
        return 0;

    if ( dp[n][m] != - 1)
        return dp[n][m];
    
    if ( s1[n-1] != s2[m-1])
        return dp[n][m] = max(LCS(s1, s2, n-1, m), LCS(s1, s2, n, m-1));

    return dp[n][m] = LCS(s1, s2, n-1, m-1) + 1;

}

int main(){

    string s1, s2;
    cin>>s1>>s2;

    cout<<LCS(s1, s2, s1.size(), s2.size());

    return 0;

}