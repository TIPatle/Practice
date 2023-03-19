// We are given an array ‘ARR’ with N positive integers.
// We need to find if we can partition the array into two subsets 
// such that the sum of elements of each subset is equal to the other.

// If we can partition, return true else return false

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
bool partitionSubsetEqual(vector<int> &arr, int n, int k){
    return subsetSumSpace(arr, n, k);
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
    if(sum%2) cout<<false<<endl;
    else cout<<partitionSubsetEqual(arr, n, sum/2)<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--) solve();


    return 0;

}