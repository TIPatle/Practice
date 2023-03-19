// Frog Jump Problem
// Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. 
// At a time the frog can climb either 1, 2, .., K steps. A height[N] array is also given. 
// Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is 
// abs(height[i]- height[j]), where abs() means the absolute difference. 
// We need to return the minimum energy that can be used by the frog to jump 
// from stair 0 to stair N-1.

#include<bits/stdc++.h>
using namespace std;

int minEnergyConsumed(vector<int> &height, int n, int k, vector<int> &t){
    if(n<=1) return 0;
    if(n==2) return abs(height[1]-height[0]);
    if(t[n]!= -1) return t[n];
    t[n] = INT_MAX;
    for(int i = 1; i<=k; i++){
        t[n] = min(t[n], minEnergyConsumed(height,n-i, k, t) + abs(height[n-1]-height[n-1-i]));
    }
    return t[n];
}

int main(){
    int n;
    cin>>n;
    vector<int> height(n);
    for(int i = 0; i<n; i++)
        cin>>height[i];
    vector<int> t(n+1, -1);
    cout<<minEnergyConsumed(height, n, 3, t)<<endl;
    return 0;
}