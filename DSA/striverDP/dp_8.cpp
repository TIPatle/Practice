// We are given an “N*M” Maze. The maze contains some obstacles. 
// A cell is ‘blockage’ in the maze if its value is -1. 0 represents non-blockage. 
// There is no path possible through a blocked cell.
// We need to count the total number of unique paths from the top-left corner of the maze 
// to the bottom-right corner. At every cell, we can move either down or towards the right.

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

int possiblePath(vii& obstacleGrid, int n, int m, vii &t){
    if(n<1 || m<1) return 0;
    if(obstacleGrid[n-1][m-1]==1) return 0;
    if(n==1&&m==1) return 1;
    if(t[n][m] != -1) return t[n][m];
    return t[n][m] = possiblePath(obstacleGrid, n-1, m, t) + possiblePath(obstacleGrid, n, m-1, t);
}
int possiblePath(vii& obstacleGrid){
    if(obstacleGrid[0][0]==1) return 0;
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vii t(n+1, vi(m+1, 0));
    t[1][1] = 1;
    rep(i, 1, n+1){
        rep(j, 1, m+1){
            if((i==j)&& j==1) continue;
            if(obstacleGrid[i-1][j-1]==1) continue;
            t[i][j] = t[i-1][j] + t[i][j-1];
        }
    }
    return t[n][m];
}
int possiblePathS(vii& obstacleGrid){
    if(obstacleGrid[0][0]==1) return 0;
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vii t(2, vi(m+1, 0));
    t[1][1] = 1;
    rep(i, 1, n+1){
        rep(j, 1, m+1){
            if((i==j)&& j==1) continue;
            if(obstacleGrid[i-1][j-1]==1){      // problem is here when we space optimising it 
                t[i%2][j] = 0;
                continue;
            }             
            t[i%2][j] = t[(i-1)%2][j] + t[i%2][j-1];
        }
    }
    return t[n%2][m];
}
void solve(){
    int n, m;
    cin>>n>>m;
    vii obstacleGrid(n, vi(m));
    rep(i, 0, n){
        rep(j,0, m){
            cin>>obstacleGrid[i][j];
        }
    }
    vii t(n+1, vi(m+1,-1));
    cout<<possiblePathS(obstacleGrid)<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--) solve();


    return 0;

}