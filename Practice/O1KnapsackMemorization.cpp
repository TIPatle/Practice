#include <iostream>
#define N 1000

using namespace std;

int dp[N] = {0};

int knapsack( int wt[], int val[], int w, int n){

    if ( n == 0 || w == 0 )
        return 0;

    if ( dp[n] )    
        return dp[n];

    if ( w < wt[n-1] )
        return dp[n] = knapsack(wt, val, w, n-1);

    return dp[n] = max(knapsack(wt, val, w, n-1 ), val[n-1] + knapsack(wt, val, w-wt[n-1], n-1));

}

int main(){

    int n;
    cin>>n;

    int wt[n], val[n];
    for ( int i = 0; i<n; i++ )
        cin>>wt[i]>>val[i];

    int w;
    cin>>w;

    cout<<knapsack(wt, val, w, n)<<endl;

    return 0;

}