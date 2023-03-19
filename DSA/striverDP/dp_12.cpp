// You are given an r rows and c cols matrix grid representing a field of cherries where grid[i][j] represents 
// the number of chocolates that you can collect from the (i, j) cell.

// You have two robots that can collect chocolates for you:

// Robot #1 is located at the top-left corner (0, 0), and
// Robot #2 is located at the top-right corner (0, cols - 1).
// Return the maximum number of chocolates collection using both robots by following the rules below:

// From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
// When any robot passes through a cell, It picks up all chocolates, and the cell becomes an empty cell.
// When both robots stay in the same cell, only one takes the chocolates.
// Both robots cannot move outside of the grid at any moment.
// Both robots should reach the bottom row in grid.

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
int maxChocolatePickup(vector<vector<int>> &grid, int i, int j1, int j2){
    // Out of Bound
    if(j1<0||j1>=grid[0].size()||j2<0||j2>=grid[0].size()) return -1e8;
    // Base case 
    if(i==(grid.size()-1)){
        if(j1==j2) return grid[i][j1];
        return grid[i][j1]+grid[i][j2];
    }
    // All Combos
    int ans = INT_MIN;
    for(int l = -1; l<=1; l++){
        for(int k = -1; k<=1; k++){
            ans = max(ans, maxChocolatePickup(grid, i+1, j1+l, j2+k));
        }
    }
    if(j1==j2) return ans + grid[i][j1];
    return ans + grid[i][j1]+grid[i][j2];
}

// Time complexity : O(n*m*m*9)  Space complexity : O(n*m*m)  Auxiallary space : o(n)
int maxChocolatePickup(vector<vector<int>> &grid, int i, int j1, int j2, vector<vector<vector<int>>> &t){
    if(j1<0||j2<0||j1>=grid[0].size()||j2>=grid[0].size())
        return -1e8;
    if(i==grid.size()-1){
        if(j1==j2) return grid[i][j1];
        return grid[i][j1]+grid[i][j2];
    }
    if(t[i][j1][j2] != -1 ) return t[i][j1][j2];
    int ans = INT_MIN;
    for(int l = -1; l<=1; l++){
        for(int k = -1; k<=1; k++){
            ans = max(ans, maxChocolatePickup(grid, i+1, j1+l, j2+k, t));
        }
    }

    if(j1==j2) return t[i][j1][j2]=ans+grid[i][j1];
    return t[i][j1][j2] = ans + grid[i][j1]+grid[i][j2];
    
}
int maxchocolate(vector<vector<int>> &grid, int n, int m){
    vector<vector<vector<int>>> t(n, vii(m, vi(m, -1)));
    // edge case
    for(int j1 = 0; j1<m; j1++){
        for(int j2 = 0; j2<m; j2++){
            if(j1==j2){
                t[n-1][j1][j2] = grid[n-1][j1];
            }
            else{
                t[n-1][j1][j2] = grid[n-1][j1]+grid[n-1][j2];
            }
        }
    }
    for(int i = n-2; i>=0; i--){
        for(int j1 = 0; j1<m; j1++){
            for(int j2 = 0; j2<m; j2++){
                int ans = INT_MIN;
                for(int l = -1; l<=1; l++){
                    for(int k = -1; k<=1; k++){
                        if(j1+l<0||j2+k<0||j1+l>=m||j2+k>=m)
                            ans = max(ans, int(-1e8));
                        else
                            ans = max(ans, t[i+1][j1+l][j2+k]);
                    }
                }
                if(j1==j2)
                    t[i][j1][j2]=ans+grid[i][j1];
                else
                    t[i][j1][j2] = ans + grid[i][j1]+grid[i][j2];
            }
        }
    }
    return t[0][0][m-1];
}
int maxchocolateSpace(vector<vector<int>> &grid, int n, int m){
    vector<vector<int>> next(m, vi(m, -1));
    // edge case
    for(int j1 = 0; j1<m; j1++){
        for(int j2 = 0; j2<m; j2++){
            if(j1==j2){
                next[j1][j2] = grid[n-1][j1];
            }
            else{
                next[j1][j2] = grid[n-1][j1]+grid[n-1][j2];
            }
        }
    }
    vector<vector<int>> curr(m, vi(m));
    for(int i = n-2; i>=0; i--){
        for(int j1 = 0; j1<m; j1++){
            for(int j2 = 0; j2<m; j2++){
                int ans = INT_MIN;
                for(int l = -1; l<=1; l++){
                    for(int k = -1; k<=1; k++){
                        if(j1+l<0||j2+k<0||j1+l>=m||j2+k>=m)
                            ans = max(ans, int(-1e8));
                        else
                            ans = max(ans, next[j1+l][j2+k]);
                    }
                }
                if(j1==j2)
                    curr[j1][j2]=ans+grid[i][j1];
                else
                    curr[j1][j2] = ans + grid[i][j1]+grid[i][j2];
            }
        }
        next = curr;
    }
    return curr[0][m-1];
}
void solve(){
    int n, m;
    cin>>n>>m;
    vii grid(n, vi(m));
    for(int i =0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }
    // vector<vector<vector<int>>> t(n, vii(m, vi(m, -1)));
    cout<<maxchocolateSpace(grid, n, m)<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--) solve();


    return 0;

}