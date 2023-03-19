#include <bits/stdc++.h>

#define N 1e7
#define M 1e5

#define vi vector<int>
#define vii vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pii pair<int, int>

#define rep(i, a, b) for(int i = a; i<b; i++)
#define decrep(i, a, b) for ( int i = a; i>=b; i--)
#define repit(it, s) for ( auto it : s)

using namespace std;

int lcs(string& s, int i , int j, vector<vector<int>>& t){
    if ( i >= j )
        return 0;
    if ( t[i][j] != 0 )
        return t[i][j];
    if(s[i] == s[j]){
        return t[i][j] = lcs(s, i+1, j-1, t)+1;
    }
    return t[i][j] = max(lcs(s, i+1, j, t), lcs(s, i, j-1, t));
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<int>> t = vector<vector<int>>(n+2, vector<int>(n+2, 0));
    cout<<lcs(s, 0, n-1, t)<<endl;
    
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--) solve();


    return 0;

}