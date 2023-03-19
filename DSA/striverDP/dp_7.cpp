// Given a A X B matrix with your initial position at the top-left cell, 
// find the number of possible unique paths to reach the bottom-right cell of the 
// matrix from the initial position.

// Note: Possible moves can be either down or right at any point in time, 
// i.e., we can move to matrix[i+1][j] or matrix[i][j+1] from matrix[i][j].

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

int uniqueWays(int n, int m, vii &t){
    if(n==1||m==1) return 1;
    if(t[n][m]!=-1) return t[n][m];
    return t[n][m] = uniqueWays(n-1,m,t)+uniqueWays(n,m-1,t);
}
int uniqueways(int n, int m){
    vii t(n+1, vi(m+1, 1));
    rep(i, 2, n+1){
        rep(j, 2, m+1){
            t[i][j] = t[i-1][j]+t[i][j-1];
        }
    }
    return t[n][m];
}
int uniquewayS(int n, int m){
    vii t(2, vi(m+1, 1));
    rep(i, 2, n+1){
        rep(j, 2, m+1){
            t[i%2][j] = t[(i-1)%2][j]+t[i%2][j-1];
        }
    }
    return t[n%2][m];
}
void solve(){
    int n, m;
    cin>>n>>m;
    vii t(n+1, vi(m+1, -1));
    cout<<uniquewayS(n, m)<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--) solve();


    return 0;

}