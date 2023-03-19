// Climbing Stairs. Give me distinct ways to reach at top of the stair
// Basically FIbonnaci series 
#include <bits/stdc++.h>
using namespace std;
int countDistinctWays(int n){
    // Count distinct ways to climb stair of n step
    // TC: O(2^n) SC: O(n)
    if(n<=0){
        if(n==0) return 1;
        return 0;
    }
    return countDistinctWays(n-1) + countDistinctWays(n-2);
}
int countDistinctWays(int n, vector<int> &t){
    // Count distinct ways to climb stair of n step
    // TC: O(n) SC: O(n) + O(n)
    if(n<=1) return 1;
    if(t[n]!=-1) return t[n];
    return t[n] = countDistinctWays(n-1, t) + countDistinctWays(n-2, t);
}
int countDistinctWaysI(int n){
    // Count distinct ways to climb stair of n step
    // TC: O(n) SC: O(n)
    vector<int> t(n+1, -1);
    t[0] = 1;
    t[1] = 1;
    for(int i = 2; i<=n; i++){
        t[i] = t[i-1]+t[i-2];
    }
    return t[n];
}
int countDistinctWaysM(int n){
    // Count distinct ways to climb stair of n step
    // TC: O(n) SC: O(1)
    // Edge Cases 
    if(n<=1) return n;
    int p1 = 1;
    int p2 = 0;
    int curr;
    for(int i = 2; i<=n; i++ ){
        curr = p1+p2;
        p2 = p1;
        p1 = curr;
    }
    return curr;
}
int main(){
    int n;
    cin>>n;
    vector<int> t(n+1, -1);
    cout<<countDistinctWaysM(n)<<endl;
    return 0;
}