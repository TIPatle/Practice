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
int lis(vi& arr, int n, int prev){
    if(n==0){
        if(prev==arr.size()) return 1;
        if(arr[0]<arr[prev]) return 1;
        return 0;
    }
    int notPick = lis(arr, n-1, prev);
    int pick=0;
    if(prev==arr.size()) pick = 1+lis(arr, n-1, n);
    else if(arr[n]<arr[prev]) pick = 1+lis(arr, n-1, n);
    return max(pick, notPick);
}
int LISTab(vi& arr, int n){
    vector<vector<int>> t(n, vector<int>(n+1, 0));
    t[0][n]=1;
    for(int i=1; i<n; i++){
        if(arr[0]<arr[i]) t[0][i]=1;
    }
    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++){
            int notPick = t[i-1][j];
            int pick=0;
            if(j==n||arr[i]<arr[j]) pick = 1+t[i-1][i];
            t[i][j]= max(pick, notPick);
        }
    }
    return t[n-1][n];
}
void solve(){
    int n;
    cin>>n;
    vi arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<LISTab(arr, n)<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--) solve();


    return 0;

}