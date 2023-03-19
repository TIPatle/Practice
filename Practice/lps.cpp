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

int LCS( string a, string b, int n, int m ){

    if ( n == 0 || m == 0 )
        return 0;

    if ( a[n-1] == b[m-1] )
        return 1 + LCS(a, b, n-1, m-1);

    return max(LCS(a, b, n-1, m), LCS(a, b, n, m-1) );

}

int main(){
    
    string a;
    cin>>a;
    string b = a;
    reverse(b.begin(), b.end());
    cout<<LCS(a, b, a.length(), a.length());

    return 0;

}