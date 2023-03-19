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

int cutRod(vector<int> &price, int n, int length){
    if(n==0){
        return length*price[0];
    }
    int notPick = cutRod(price, n-1, length);
    int pick = INT_MIN;
    if((n+1)>=length) pick = cutRod(price, n, length-(n+1))+price[n];
    return max(pick, notPick);
}
int cutRod(vector<int> &price, int n, int length, vector<vector<int>>&t){
    if(n==0){
        return length*price[0];
    }
    if(t[n][length] != -1) return t[n][length];
    int notPick = cutRod(price, n-1, length, t);
    int pick = INT_MIN;
    if((n+1)>=length) pick = cutRod(price, n, length-(n+1), t)+price[n];
    return t[n][length] = max(pick, notPick);
}
int cutRod(vector<int> &price, int n){
    vector<vector<int>> t(n, vector<int>(n+1, 0));
    for(int i = 0; i<=n; i++ ){
        t[0][i] = i*price[0];
    }
    for(int i = 1; i<n; i++){
        for(int j = 0; j<=n; j++){
            int notPick = t[i-1][j];
            int pick = INT_MIN;
            if((i+1)>=j) pick = t[i][j-(i+1)]+price[i];
            t[i][j] = max(pick, notPick);
        }
    }
    return t[n-1][n];
}
int cutRodSpace(vector<int> &price, int n){
    vector<int> prev(n+1, 0), curr(n+1, 0);
    for(int i = 0; i<=n; i++ ){
        prev[i] = i*price[0];
    }
    for(int i = 1; i<n; i++){
        for(int j = 0; j<=n; j++){
            int notPick = prev[j];
            int pick = INT_MIN;
            if((i+1)>=j) pick = curr[j-(i+1)]+price[i];
            curr[j] = max(pick, notPick);
        }
        prev = curr;
    }
    return prev[n];
}
int cutRodSpaces(vector<int> &price, int n){
    vector<int> prev(n+1, 0);
    for(int i = 0; i<=n; i++ ){
        prev[i] = i*price[0];
    }
    for(int i = 1; i<n; i++){
        for(int j = 0; j<=n; j++){
            int notPick = prev[j];
            int pick = INT_MIN;
            if((i+1)>=j) pick = prev[j-(i+1)]+price[i];
            prev[j] = max(pick, notPick);
        }
    }
    return prev[n];
}
void solve(){
    int n;
    cin>>n;
    vi price(n);
    for(int i = 0; i<n; i++) cin>>price[i];
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--) solve();


    return 0;

}