// partition set into 2 subsets with min absolute sum diff

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

int minDiff(vector<int> &arr, int n, int s, int sum){
    if(n==0){
        return abs(sum-2*s);
    }
    int ans1 = minDiff(arr, n-1, s+arr[n-1], sum);
    int ans2 = minDiff(arr, n-1, s, sum);
    return min(ans1, ans2);
}
int minDiff(vector<int> &arr, int n, int s, int sum, vector<vector<int>> &t){
    if(n==0){
        return abs(sum-2*s);
    }
    if(t[n][s]!=-1) return t[n][s];
    int ans1 = minDiff(arr, n-1, s+arr[n-1], sum, t);
    int ans2 = minDiff(arr, n-1, s, sum, t);
    return t[n][s]=min(ans1, ans2);
}
int mindiff(vector<int> &arr, int n, int s, int sum){
    vector<vector<int>> t(n+1, vector<int>(sum+1));
    for(int i = 0; i<=sum; i++){
        t[0][i]=abs(sum-2*i);
    }
    for(int i = 1; i<=n; i++){
        for(int j=0; j<=sum; j++){
            int ans1 = t[i-1][j];
            int ans2 = t[i-1][j+arr[i-1]];
            t[i][j] = min(ans1, ans2);
        }
    }
    return t[n][sum];
}
void solve(){
    int n;
    cin>>n;
    vi arr(n);
    int sum = 0;
    for(int i =0; i<n; i++){
        cin>>arr[i];
        sum += arr[i];
    }
    vector<vector<int>> t(n+1, vector<int>(sum+1, -1));
    cout<<minDiff(arr, n, 0, sum, t)<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--) solve();


    return 0;

}