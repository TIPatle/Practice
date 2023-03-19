#include <iostream>
#include <vector>

using namespace std;

vector <int> weight(1000);
vector <int> values(1000);

vector <vector<int>> dp(1000, vector<int> (1000, -1));

int knapsack( int n, int w ){

    if ( w <= 0 )
        return 0;

    if ( n <= 0 )
        return 0;

    if ( dp[n][w] != -1)
        return dp[n][w];

    if ( weight[n-1] > w)
        return knapsack(n-1, w);

    return dp[n][w] = max(knapsack(n-1, w), knapsack(n-1, w - weight[n-1]) + values[n-1]);

}

int main(){

    int n;
    cin>>n;

    for ( int i = 0; i<n; i++ )
        cin>>weight[i];

    for ( int i = 0; i<n; i++ )
        cin>>values[i];

    int w;
    cin>>w;

    cout<<knapsack(n, w)<<endl;

    return 0;

}