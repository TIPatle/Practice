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

int findWays(vector<int>&arr, int n, int target){
    if(n==0){
        return (target%arr[0]==0);
    }
    int notPick = findWays(arr, n-1, target);
    int pick = 0;
    if(arr[n]<=target) pick = findWays(arr, n, target-arr[n]);
    return notPick + pick;
}
int findWays(vector<int>&arr, int n, int target, vector<vector<int>>& t){
    if(n==0){
        return (target%arr[0]==0);
    }
    if(t[n][target] != -1) return t[n][target];
    int notPick = findWays(arr, n-1, target);
    int pick = 0;
    if(arr[n]<=target) pick = findWays(arr, n, target-arr[n]);
    return t[n][target] = notPick + pick;
}
int findways(vector<int>&arr, int n, int target){
    vector<vector<int>> t(n, vector<int>(target+1, 0));
    for(int i = 0; i<=target; i++){
        if(i%arr[0]==0) t[0][i]=1;
    }
    for(int i = 1; i<n; i++){
        for(int j = 0; j<=target; j++){
            int notPick = t[i-1][j];
            int pick = 0;
            if(arr[i]<=j) pick = t[i][j-arr[i]];
            t[i][j] = notPick + pick;
        }
    }
    return t[n-1][target];
}
int findwaysSpace(vector<int>&arr, int n, int target){
    vector<int> prev(target+1, 0);
    vector<int> curr(target+1, 0);
    for(int i = 0; i<=target; i++){
        if(i%arr[0]==0) prev[i]=1;
    }
    for(int i = 1; i<n; i++){
        for(int j = 0; j<=target; j++){
            int notPick = prev[j];
            int pick = 0;
            if(arr[i]<=j) pick = curr[j-arr[i]];
            curr[j] = notPick + pick;
        }
        prev = curr;
    }
    return prev[target];
}
int findwaysSpaces(vector<int>&arr, int n, int target){
    vector<int> prev(target+1, 0);
    for(int i = 0; i<=target; i++){
        if(i%arr[0]==0) prev[i]=1;
    }
    for(int i = 1; i<n; i++){
        for(int j = 0; j<=target; j++){
            int notPick = prev[j];
            int pick = 0;
            if(arr[i]<=j) pick = prev[j-arr[i]];
            prev[j] = notPick + pick;
        }
    }
    return prev[target];
}
void solve(){
    int n, target;
    cin>>n>>target;
    vi arr(n);
    rep(i, 0, n) cin>>arr[i];
    cout<<findWays(arr, n-1, target)<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--) solve();


    return 0;

}