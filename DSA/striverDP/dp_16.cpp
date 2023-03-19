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

// int subsetSumK(vector<int>&arr, int n, int k){
//     if(n==0){
//         if(k==0) return 1;
//         return 0;
//     }
//     int notPick = subsetSumK(arr, n-1, k);
//     int pick = 0;
//     if(k>=arr[n-1]) pick = subsetSumK(arr, n-1, k-arr[n-1]);
//     return pick+notPick;
// }
int subsetSumK(vector<int>&arr, int n, int k){
    if(n==0){
        if(k==0 && arr[0]==0) return 2;
        if(k==0||k==arr[0]) return 1;
        return 0;
    }
    int notPick = subsetSumK(arr, n-1, k);
    int pick = 0;
    if(k>=arr[n]) pick = subsetSumK(arr, n-1, k-arr[n]);
    return pick+notPick;
}
int subsetSumK(vector<int>&arr, int n, int k, vector<vector<int>> &t){
    if(k==0) return 1;
    if(n==0){
        return (arr[n]==k);
    }
    if(t[n][k]!=-1) return t[n][k];
    int notPick = subsetSumK(arr, n-1, k, t);
    int pick = 0;
    if(k>=arr[n]) pick = subsetSumK(arr, n-1, k-arr[n], t);
    return t[n][k]=pick+notPick;
}
int subsetSum(vector<int>&arr, int n, int k){
    vector<vector<int>> t(n, vector<int>(k+1));
    for(int i=0; i<n; i++){
        t[i][0]=1;
    }
    if(arr[0]<=k) t[0][arr[0]]=1;
    for(int i = 1; i<n; i++){
        for(int j=0; j<=k; j++){
            int notPick = t[n-1][k];
            int pick = 0;
            if(j>=arr[i]) pick = t[n-1][j-arr[i]];
            t[i][j]=pick+notPick;
        }
    }
    return t[n-1][k];
}
int subsetSumSpace(vector<int>&arr, int n, int k){
    vector<int> prev(k+1);
    vector<int> curr(k+1);
    prev[0]=1;
    curr[0]=1;
    if(arr[0]<=k) prev[arr[0]]=1;
    for(int i = 1; i<n; i++){
        for(int j=0; j<=k; j++){
            int notPick = prev[k];
            int pick = 0;
            if(j>=arr[i]) pick = prev[j-arr[i]];
            curr[j]=pick+notPick;
        }
        prev = curr;
    }
    return prev[k];
}
void solve(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vi arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    vector<vector<int>> t(n, vector<int>(k+1, -1));
    cout<<subsetSumK(arr, n-1, k, t)<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--) solve();


    return 0;

}