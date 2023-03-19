// In this article, we will solve the most asked coding interview problem: Subset sum equal to target.

// In this article, we will be going to understand the pattern of dynamic programming
// on subsequences of an array. We will be using the problem “Subset Sum Equal to K”.

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

bool subsetSumK(vector<int>& arr, int n, int k ){
    if (k==0) return true;
    if (n<0||k<0) return false;
    // Pickup
    if(subsetSumK(arr, n-1, k-arr[n])) return true;
    // Notpickup
    return subsetSumK(arr, n-1, k);
}
bool subsetSumk(vector<int>& arr, int n, int k, vector<vector<int>> &t){
    if(k==0) return true;
    if(n<0) return false;
    if(t[n][k]!=-1) return t[n][k];
    if(subsetSumk(arr, n-1, k-arr[n], t)) return t[n][k]=true;
    return t[n][k] = subsetSumk(arr, n-1, k, t);
}
bool subsetSum(vector<int>&arr, int n, int k){
    vector<vector<int>> t(n+1, vector<int>(k+1, 0));
    for(int i = 0; i<=n; i++){
        t[i][0]=1;
    }
    t[0][arr[0]]=1;
    for(int i = 1; i<n; i++){
        for(int j = 0; j<=k; j++){
            if(arr[i]<=j){
                t[i][j]=t[i-1][j]||t[i-1][j-arr[i]];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n-1][k];
}
bool subsetSumSpace(vector<int>&arr, int n, int k){
    vector<bool> curr(k+1, 0);
    vector<bool> prev(k+1, 0);
    prev[0] = 1;
    curr[0] = 1;
    prev[arr[0]] = 1;

    for(int i = 1; i<n; i++){
        for(int j = 0; j<=k; j++){
            if(arr[i]<=j){
                curr[j]=prev[j]||prev[j-arr[i]];
            }
            else{
                curr[j]=prev[j];
            }
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
    vector<vector<int>> t(n+1, vector<int>(k+1, -1));
    cout<<subsetSum(arr, n-1, k)<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--) solve();


    return 0;

}