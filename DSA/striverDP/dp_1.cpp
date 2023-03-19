// Fibonnaci Series
#include<bits/stdc++.h>
using namespace std;

int fibonnaci(int n){
    // Calculate ith Fibonnaci Takes TC: O(2^n) SC:O(n) (Auxiallry)
    if(n<=1) return n;
    return fibonnaci(n-1)+fibonnaci(n-2);
}
int fibonnaci(int n, vector<int> &t){
    // Calculate ith fibonnaci Takes TC: O(n) SC: O(n) + O(n)
    if(n<=1) return n;
    if(t[n]!=-1) return t[n];
    return t[n] = fibonnaci(n-1, t) + fibonnaci(n-2, t);
}
int fibonnaciT(int n, vector<int> &t){
    // Calculate ith fibonnci Takes TC: O(n) SC : O(n)
    t[0] = 0;
    t[1] = 1;
    for(int i = 2; i<=n; i++){
        t[i]= t[i-1]+t[i-2];
    }
    return t[n];
}
int fibonnaciM(int n){
    // Calculate ith fibonnaci Takes TC:O(n) SC:O(1)
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
    cout<<fibonnaciM(n)<<endl;
    return 0;
}