// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, 
// which minimizes the sum of all numbers along its path.
// Note: You can only move either down or right at any point in time.

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

int minPathSum(vii& grid, int n, int m, vii& t) {
    if(n<1||m<1){
        if(n==1||m==1) return 0; 
        return 1e5;
    }
    if(t[n][m] != -1) return t[n][m];
    int ans1 = minPathSum(grid, n-1, m, t);
    int ans2 = minPathSum(grid, n, m-1, t);
    return t[n][m]=min(ans1, ans2)+grid[n-1][m-1];
}
int minPathSum(vii &grid, int n, int m){
    vii t(n+1, vi(m+1, 0));
    rep(i, 0, n+1){
        t[i][0] = 1e5;
    }
    rep(i, 0, m+1){
        t[0][i] = 1e5;
    }
    t[0][1] = t[1][0] = 0;
    rep(i, 1, n+1){
        rep(j, 1, m+1){
            t[i][j] = min(t[i-1][j], t[i][j-1])+grid[i-1][j-1];
        }
    }
    return t[n][m];
}
int minPathSum(vii &grid, int n, int m){
    vii t(2, vi(m+1, 0));
    rep(i, 0, 2){
        t[i][0] = 1e5;
    }
    rep(i, 0, m+1){
        t[0][i] = 1e5;
    }
    t[0][1] = t[1][0] = 0;
    rep(i, 1, n+1){
        rep(j, 1, m+1){
            t[i%2][j] = min(t[(i-1)%2][j], t[i%2][j-1])+grid[i-1][j-1];
        }
        // case when the i is not one then side one should be infinity which is not taken in base case
        if(i+1<=n){
            t[(i+1)%2][0] = 1e5;
        }
    }
    return t[n%2][m];
}
void solve(){
    int n, m;
    cin>>n>>m;
    vii grid(n, vi(m));
    rep(i,0,n){
        rep(j, 0, m){
            cin>>grid[i][j];
        }
    }
    vii t(n+1, vi(m+1, -1));
    cout<<minPathSum(grid, n, m)<<endl;   
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--) solve();


    return 0;

}