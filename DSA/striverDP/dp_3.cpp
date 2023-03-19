// Frog Jump Problem
// Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. 
// At a time the frog can climb either one or two steps. A height[N] array is also given. 
// Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is 
// abs(height[i]- height[j]), where abs() means the absolute difference. 
// We need to return the minimum energy that can be used by the frog to jump 
// from stair 0 to stair N-1.

#include<bits/stdc++.h>
using namespace std;

int minEnergyConsumed(vector<int> &height, int n, vector<int> &t){
    if(n<=1) return 0;
    if(n==2) return abs(height[1]-height[0]);
    if(t[n]!= -1) return t[n];
    int left = minEnergyConsumed(height,n-1, t) + abs(height[n-1]-height[n-2]);
    int right= minEnergyConsumed(height,n-2, t) + abs(height[n-1]-height[n-3]);
    return t[n] = min(left, right);
}
int minEnergyConsumed(vector<int> &height, int n){
    // Edge Case
    if(n<=1) return 0;
    if(n==2) return abs(height[1]-height[0]);
    vector<int> t;
    int p1 = abs(height[1]-height[0]);
    int p2 = 0; int curr;
    int left, right;
    for(int i = 3; i<=n; i++){
        left = p1 + abs(height[i-1]-height[i-2]);
        right = p2 + abs(height[i-1]-height[i-3]);
        curr = min(left, right);
        p2 = p1;
        p1 = curr;
    }
    return curr;
}

int main(){
    int n;
    cin>>n;
    vector<int> height(n);
    for(int i = 0; i<n; i++)
        cin>>height[i];
    vector<int> t(n+1, -1);
    cout<<minEnergyConsumed(height, n)<<endl;
    return 0;
}