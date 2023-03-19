// You are given an array/list of ‘N’ integers. You are supposed to return 
// the maximum sum of the subsequence with the constraint that 
// no two elements are adjacent in the given array/list.

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


int maximumNonAdjacentSum(vector<int> &nums, int n, vector<int> &t){
    if(n<=0) return 0;
    if(t[n]!=-1) return t[n];
    // Not Chossen the current element
    int left = maximumNonAdjacentSum(nums, n-1, t);
    // Chossen the current element 
    int right = maximumNonAdjacentSum(nums, n-2, t) + nums[n-1];
    return t[n] = max(left, right);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> t(n+1, -1);
    t[0] = 0;
    t[1] = nums[0];
    for(int i=2; i<=n; i++){
        int left = t[i-1];
        int right = t[i-2]+nums[i-1];
        t[i] = max(left, right);
    }
    return t[n];
}
int maximumNonAdjacentSumM(vector<int> &nums){
    int n = nums.size();
    vector<int> t(n+1, -1);
    int p2 = 0;
    int p1 = nums[0];
    for(int i=2; i<=n; i++){
        int left = p1;
        int right = p2+nums[i-1];
        int curr = max(left, right);
        p2 = p1;
        p1 = curr;
    }
    return p1;
}

void solve(){
    int n;
    cin>>n;
    vi arr(n);
    rep(i, 0, n) cin>>arr[i];
    vi t(n+1, -1);
    cout<<maximumNonAdjacentSum(arr)<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--) solve();


    return 0;

}