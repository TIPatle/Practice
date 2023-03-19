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

int lcs( string s1, string s2, int n, int m, int length ){

    if ( n == 0 || m == 0 )
        return length;

    if ( s1[n-1] == s2[m-1])
        return lcs(s1, s2, n-1, m-1, length + 1);

    else 
        return max(lcs(s1, s2, n-1, m, 0), lcs(s1, s2, n, m-1, 0));

}

int lcs( string s1, string s2, int n, int m ){

    vii t(n+1, vi(m+1, -1));

    rep(i, 0, n+1)
        t[i][0] = 0;

    rep(i, 0, m+1)
        t[0][i] = 0;

    rep(i, 1, n+1){

        rep(j, 1, m+1){

            if ( s1[i-1] == s2[j-1])
                t[i][j] = t[i-1][j-1] + 1;

            else
                t[i][j] = 0;

        }

    }

    return t[n][m];

}

int main(){
    
    string s1 = "abbcf";
    string s2 = "abcdaf";

    cout<<lcs(s1, s2, s1.length(), s2.length(), 0);

    return 0;

}