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
int totalProfit(vector<int>&wt, vector<int>&val, int n, int w){
    if(n==0){
        if(w>=wt[n]) return val[n];
        return 0;
    }
    int notPick = totalProfit(wt, val, n-1, w);
    int pick = INT_MIN;
    if(w>=wt[n]) pick = totalProfit(wt, val, n-1, w-wt[n])+val[n];
    return max(pick, notPick);
}
int totalProfit(vector<int>&wt, vector<int>&val, int n, int w, vector<vector<int>>&t){
    if(n==0){
        if(w>=wt[n]) return val[n];
        return 0;
    }
    if(t[n][w]!=-1) return t[n][w];
    int notPick = totalProfit(wt, val, n-1, w);
    int pick = INT_MIN;
    if(w>=wt[n]) pick = totalProfit(wt, val, n-1, w-wt[n])+val[n];
    return t[n][w] = max(pick, notPick);
}
int totalProFit(vector<int>&wt, vector<int>&val, int n, int w){
    vector<vector<int>> t(n, vector<int>(w+1, 0));
    for(int i = wt[0]; i<=w; i++){
        t[0][i]=val[0];
    }
    for(int i = 1; i<n; i++){
        for(int j = 0; j<=w; j++){
            int notPick = t[i-1][w];
            int pick = INT_MIN;
            if(w>=wt[n]) pick = t[n-1][w-wt[i]];
            t[i][w] = max(pick, notPick);
        }
    }
    return t[n-1][w];
}
int totalProFitSpace(vector<int>&wt, vector<int>&val, int n, int w){
    vector<int> curr(w+1, 0);
    vector<int> prev(w+1, 0);
    for(int i = wt[0]; i<=w; i++){
        prev[i]=val[0];
    }
    for(int i = 1; i<n; i++){
        for(int j = 0; j<=w; j++){
            int notPick = prev[w];
            int pick = INT_MIN;
            if(w>=wt[n]) pick = prev[w-wt[i]];
            curr[w] = max(pick, notPick);
        }
        prev = curr;
    }
    return prev[w];
}
int totalProFitSs(vector<int>&wt, vector<int>&val, int n, int w){
    vector<int> prev(w+1, 0);
    for(int i = wt[0]; i<=w; i++){
        prev[i]=val[0];
    }
    for(int i = 1; i<n; i++){
        for(int j = w; j>=0; j++){
            int notPick = prev[w];
            int pick = INT_MIN;
            if(w>=wt[n]) pick = prev[w-wt[i]];
            prev[w] = max(pick, notPick);
        }
    }
    return prev[w];
}
void solve(){
    int n,w;
    cin>>n>>w;
    vector<int> wt(n);
    vector<int> val(n);
    for(int i = 0; i<n; i++) cin>>wt[i];
    for(int i = 0; i<n; i++) cin>>val[i];
    cout<<totalProfit(wt, val, n-1, w)<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--) solve();


    return 0;

}