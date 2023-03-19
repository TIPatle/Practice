// Given an n x n array of integers matrix, 
// return the minimum sum of any falling path through matrix.
// A falling path starts at any element in the first row and 
// chooses the element in the next row that is either directly below or diagonally 
// left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), 
// (row + 1, col), or (row + 1, col + 1).

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

int minFallingPathSum(vii& matrix, int i, int j, int m, vii &t) {
    if(j<0||j>=m) return 1e7;
    if(i==0) return matrix[i][j];
    if(t[i][j] !=-1) return t[i][j];
    int diag1 = minFallingPathSum(matrix, i-1, j-1, m, t);
    int up = minFallingPathSum(matrix, i-1, j, m, t);
    int diag2 = minFallingPathSum(matrix, i-1, j+1, m, t);
    return t[i][j] = min(min(diag1, diag2), up) + matrix[i][j];
}
int minFallingPathSum(vector<vector<int>> &matrix, int n, int m){
    vector<vector<int>> t(n, vector<int>(m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(i==0){
                t[i][j] = matrix[i][j];
            }
            else{
                int diag1, up, diag2;
                diag1 = up = diag2 = INT_MAX;
                up = t[i-1][j];
                if(j>0) diag1 = t[i-1][j-1];
                if(j<(n-1)) diag2 = t[i-1][j+1];
                t[i][j] = min(min(diag1, diag2), up) + matrix[i][j];
            }
        }
    }
    int ans = INT_MAX;
    for(int j = 0; j<m; j++){
        ans = min(ans, t[n-1][j]);
    }
    return ans;
}
int minFallingPathSumS(vector<vector<int>> &matrix, int n, int m){
    vector<int> prev(m);
    vector<int> curr(m);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(i==0){
                curr[j] = matrix[i][j];
            }
            else{
                int diag1, up, diag2;
                diag1 = up = diag2 = INT_MAX;
                up = prev[j];
                if(j>0) diag1 = prev[j-1];
                if(j<(n-1)) diag2 = prev[j+1];
                curr[j] = min(min(diag1, diag2), up) + matrix[i][j];
            }
        }
        prev = curr;
    }
    int ans = INT_MAX;
    for(int j = 0; j<m; j++){
        ans = min(ans, prev[j]);
    }
    return ans;
}
void solve(){
    int n, m;
    cin>>n>>m;
    vii matrix(n, vi(m));
    rep(i, 0, n){
        rep(j,0, m){
            cin>>matrix[i][j];
        }
    }
    int ans = INT_MAX;
    for(int j = 0; j<m; j++){
        ans = min(ans, minFallingPathSum(matrix, n-1, j, m));
    }
    cout<<ans<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--) solve();


    return 0;

}