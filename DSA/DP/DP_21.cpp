#include <iostream>
#include <vector>

using namespace std;

vector <int> coins(1e5);

int solve(int i, int j){

    if ( i == j )
        return coins[i];

    if ( i > j)
        return 0;

    int l = coins[i] + min(solve(i+2, j), solve(i+1, j-1));
    int r = coins[j] + min(solve(i, j-2), solve(i+1, j-1) );

    return max(l, r);

}

int main(){

    int n;
    cin>>n;

    for ( int i = 0; i<n; i++ )
        cin>>coins[i];

    cout<<solve(0, n-1)<<endl;

    return 0;

}