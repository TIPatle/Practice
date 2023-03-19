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

int lensuperString ( string s1, string s2, int n, int m){

    if ( n == 0 || m == 0)
        return n + m;

    if ( s1[n-1] == s2[m-1] )
        return 1 + lensuperString(s1, s2, n-1, m-1);

    return min( 1 + lensuperString(s1, s2, n-1, m), 1 + lensuperString(s1, s2, n, m-1));

}

vii t;

int shortop( string s1, string s2, int n, int m){

    rep(i, 0, n+1)
        t[i][0] = i;

    rep(i, 0, m+1)
        t[0][i] = i;

    rep(i, 1, n+1){

        rep(j, 1, m+1){

            if ( s1[i-1] == s2[j-1] )
                t[i][j] = 1 + t[i-1][j-1];

            else 
                t[i][j] = 1 + min(t[i-1][j], t[i][j-1]);

        }

    }

    return t[n][m];

}

int lcs( string s1, string s2, int n, int m ){

    if ( n == 0 || m == 0)
        return 0;

    if ( s1[n-1] == s2[m-1] )
        return 1 + lensuperString(s1, s2, n-1, m-1);

    return max(lensuperString(s1, s2, n-1, m), lensuperString(s1, s2, n, m-1));

}

int lensuper( string s1, string s2, int n, int m ){

    return m + n - lcs(s1, s2, n, m);

}

string lenString ( string s1, string s2, int n, int m){

    if ( n == 0 || m == 0)
        return s1.substr(0, n) + s2.substr(0, m);

    if ( s1[n-1] == s2[m-1] )
        return lenString(s1, s2, n-1, m-1) + s1[n-1];
    
    string x = lenString(s1, s2, n-1, m) + s1[n-1];
    string y = lenString(s1, s2, n, m-1) + s2[m-1];

    if ( x.length() >= y.length())
        return y;

    return x;

}

string lenstr ( string s1, string s2, int n, int m ){

    int t[n+1][m+1];

    for ( int i = 1; i<=n; i++ )
        t[i][0] = 1;

    for ( int i = 1; i<=m; i++ )
        t[0][i] = 1;

    t[0][0] = 0;

    string ans = "";
    for ( int i = 1; i<=n; i++ ){

        for ( int j = 1; j<=m; j++ ){

            if ( s1[i] == s2[j] ){

                ans.push_back(s1[i-1]);
                t[i][j] = t[i-1][j-1] + 1;

            }

            else {

                if ( t[i-1][j] > t[i][j-1] ){
                    
                    ans.push_back(s2[j-1]);
                    t[i][j] = t[i][j-1] + 1;

                }

                else {

                    ans.push_back(s1[i-1]);                   
                    t[i][j] = t[i-1][j] + 1;

                }

            }

        }

    }

    return ans;

}

int main(){
    
    string s1 = "abc";
    string s2 = "axyc";

    int  n = s1.length();
    int m = s2.length();

    t = vii(n+1, vi (m+1, -1));
    cout<<lenstr(s1, s2, s1.length(), s2.length());

    return 0;

}