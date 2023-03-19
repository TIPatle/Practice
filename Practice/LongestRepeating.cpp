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

string longestReaptingSubsequence( string a, string b, int n, int m){

    if ( n == 0 || m == 0  )
        return "";

    if ( a[n-1] == b[m-1] && n != m ){
        
        string s1 = longestReaptingSubsequence(a, b, n-1, m-1);
        s1.push_back( a[n-1] );

        return s1;

    }    

    string s2 = longestReaptingSubsequence(a, b, n-1, m);
    string s3 = longestReaptingSubsequence(a, b, n, m-1);

    if ( s2.length() > s3.length() )
        return s2;

    return s3;

}

int main(){

    string s;
    cin>>s;

    cout<<longestReaptingSubsequence(s, s, s.length(), s.length());

    return 0;

}