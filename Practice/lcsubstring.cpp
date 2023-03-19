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

vector<vector<string>> t;

string lcsmemo( string s1, string s2, int n, int m ){

    if ( n == 0 || m == 0 )
        return "";

    if ( t[n][m] != "" )
        return t[n][m];

    if ( s1[n-1] == s2[m-1])
        return t[n][m] = lcsmemo(s1, s2, n-1, m-1) + s1[n-1];

    string k1 = lcsmemo(s1, s2, n, m-1);
    string k2 = lcsmemo(s1, s2, n-1, m);

    if ( k1.length() > k2.length() )
        return t[n][m] = k1;

    return t[n][m] = k2;

}

string lcs( string s1, string s2, int n, int m ){

    if ( n == 0 || m == 0 )
        return "";

    if ( s1[n-1] == s2[m-1])
        return lcs(s1, s2, n-1, m-1) + s1[n-1];

    string k1 = lcs(s1, s2, n, m-1);
    string k2 = lcs(s1, s2, n-1, m);

    if ( k1.length() > k2.length() )
        return k1;

    return k2;

}

string lcstop( string s1, string s2, int n, int m ){

    rep(i, 0, n+1)
        t[i][0] = "";

    rep(i, 0, m+1)
        t[0][i] = "";

    rep(i, 1, n+1){

        rep(j, 1, m+1){

            if ( s1[i-1] == s2[j-1])
                t[i][j] = t[i-1][j-1] + s1[i-1];

            else {

                if ( t[i-1][j].length() > t[i][j-1].length() )
                    t[i][j] = t[i-1][j];

                else 
                    t[i][j] = t[i][j-1];

            }

        }

    }

    return t[n][m];

}

int main(){
    
    string s1 = "aaaabbaa";
    string s2 = "aabbaaaa";

    int n = s1.length();
    int m = s2.length();

    t = vector<vector<string>>(n+1, vector<string>(m+1, ""));

    cout<<lcstop(s1, s2, n, m);

    return 0;

}