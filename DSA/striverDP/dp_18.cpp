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

int minCoins(vector<int> d, int n, int target){
    if(n==0){
        if(d[0]<=target && target%d[0]==0) return target/d[0];
        return 1e7;
    }
    int notPick = minCoins(d, n-1, target);
    int pick = INT_MAX;
    if(d[n]<=target) pick = minCoins(d, n, target-d[n])+1;
    return min(pick, notPick);
}
int minCoins(vector<int>&d, int n, int target, vector<vector<int>> &t){
    if(n==0){
        if(d[0]<=target && target%d[0]==0) return target/d[0];
        return 1e7;
    }
    if(t[n][target]!=-1) return t[n][target];
    int notPick = minCoins(d, n-1, target, t);
    int pick = INT_MAX;
    if(d[n]<=target) pick = minCoins(d, n, target-d[n], t)+1;
    return t[n][target]=min(pick, notPick);
}
int minCoinsChange(vector<int>&d, int n, int target){
    vector<vector<int>> t(n, vector<int>(target+1, 1e7));
    for(int i = d[0]; i<=target; i++){
        if(i%d[0]==0) t[0][i]=i/d[0];
    }
    for(int i = 1; i<n; i++){
        for(int j = 0; j<=target; j++){
            int notPick = t[i-1][j];
            int pick = INT_MAX;
            if(d[n]<=target) pick = t[i-1][j-d[i]]+1;
            t[i][j] = min(pick, notPick);
        }
    }
    return t[n-1][target];
}
int minCoinsChangeSpace(vector<int>&d, int n, int target){
    vector<int> prev(target+1, 1e7);
    vector<int> curr(target+1, 1e7);
    for(int i = d[0]; i<=target; i++){
        if(i%d[0]==0) prev[i]=i/d[0];
    }
    for(int i = 1; i<n; i++){
        for(int j = 0; j<=target; j++){
            int notPick = prev[j];
            int pick = INT_MAX;
            if(d[n]<=target) pick = prev[j-d[i]]+1;
            curr[j] = min(pick, notPick);
        }
        prev = curr;
    }
    return prev[target];
}
int minCoinsChangeSpaceS(vector<int>&d, int n, int target){
    vector<int> prev(target+1, 1e7);
    for(int i = d[0]; i<=target; i++){
        if(i%d[0]==0) prev[i]=i/d[0];
    }
    for(int i = 1; i<n; i++){
        for(int j = target; j>=0; j--){
            int notPick = prev[j];
            int pick = INT_MAX;
            if(d[n]<=target) pick = prev[j-d[i]]+1;
            prev[j] = min(pick, notPick);
        }
    }
    return prev[target];
}
void solve(){
    int target;
    cin>>target;
    int n;
    cin>>n;
    vi denomination(n);
    for(int i = 0; i<n; i++) cin>>denomination[i];
    cout<<minCoins(denomination, n-1, target)<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--) solve();


    return 0;

}