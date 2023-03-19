// O--n knapsack Problem

#include <iostream>

using namespace std;

int weight[int(1e5)];
int values[int(1e5)];

int solve ( int i, int j, int w ){

    if ( i == j )
        return values[i];

    if( j < i )
        return 0;

    if ( w-weight[j-1] < 0 )
        solve(i, j-1, w);

    return max(solve(i, j, w-weight[j-1]) + values[j], solve(i, j-1, w));

}

int main(){

    int n;
    cin>>n;

    for ( int i = 0; i<n; i++)
        cin>>weight[i];

    for(int i = 0; i<n; i++ )
        cin>>values[i];

    int w;
    cin>>w;

    cout<<solve(0, n, w)<<endl;

    return 0;

}