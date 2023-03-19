// Given a triangle array, return the minimum path sum from top to bottom.
// For each step, you may move to an adjacent number of the row below. 
// More formally, if you are on index i on the current row, you may move to either index i 
// or index i + 1 on the next row.

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
 
int minimumTotal(vii& triangle, int i, int j, vii& t){
    if(i==triangle.size()-1) return triangle[i][j];
    if(t[i][j] != -1) return t[i][j];
    int down = minimumTotal(triangle, i+1, j, t);
    int diagonal = minimumTotal(triangle, i+1, j+1, t);
    return t[i][j] = min(down, diagonal) + triangle[i][j];
}
int minimumTotal(vii& triangle, int n, int m){
    vii t(n, vi(m));
    decrep(i, n-1, 0){
        decrep(j, m-1, 0){
            if(i==(n-1)){
                t[i][j] = triangle[i][j];
            }else{
                int down = t[i+1][j];
                int diagonal = t[i+1][j+1];
                t[i][j] = min(down, diagonal)+triangle[i][j];
            }
        }
        m--;
    }
    return t[0][0];
}
int minimumTotalS(vii& triangle, int n, int m){
    vi next(m);
    decrep(i, n-1, 0){
        vi curr(m);
        decrep(j, m-1, 0){
            if(i==(n-1)){
                curr[j] = triangle[i][j];
            }else{
                int down = next[j];
                int diagonal = next[j+1];
                curr[j] = min(down, diagonal)+triangle[i][j];
            }
        }
        m--;
        next = curr;
    }
    return next[0];
}
 void solve(){
    int n, m;
    cin>>n>>m;
    vii arr(n, vi(m));
    rep(i, 0, n){
        rep(j,0, m){
            cin>>arr[i][j];
        }
    }
    vii t(n, vi(m, -1));    
 }
 
 int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
 
    while(t--) solve();
 
 
    return 0;
 
 }