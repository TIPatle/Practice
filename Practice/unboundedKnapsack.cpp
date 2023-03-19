#include <iostream>

using namespace std;

int maxKnapsack(int wt[], int val[], int n, int k){

    if ( n == 0 || k == 0 )
        return 0;

    if ( k >= wt[n-1] )
        return max(maxKnapsack(wt, val, n-1, k), val[n-1] + maxKnapsack(wt, val, n, k-wt[n-1]));

    return maxKnapsack(wt, val, n - 1, k);

}

int main(){

    int n;
    cin>>n;

    int val[n];
    int wt[n];
    for ( int i = 0; i<n; i++ )
        cin>>wt[i]>>val[i];

    int k;
    cin>>k;

    cout<<maxKnapsack(wt, val, n, k)<<endl;

    return 0;

}