#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> dp(100, vector<int> (100, -1));

int lcs (string &a, string &b, int n, int m){

    if ( n == 0 || m == 0 )
        return 0;

    if ( dp[n][m] != -1 )
        return dp[n][m];

    if ( a[n-1] == b [m-1] )
        return dp[n][m] =  1 + lcs(a, b, n-1, m-1);

    return dp[n][m] = max(lcs(a, b, n-1, m), lcs(a, b, n, m-1));

}

int main(){

    string a, b;
    cin>>a>>b;

    cout<<lcs(a, b, a.length(), b.length());

    return 0;

}