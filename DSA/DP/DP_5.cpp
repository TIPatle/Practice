// coins change Problem 

#include <iostream>
#include <vector>

using namespace std;

int change( vector<int> &coins, int n, int val ){

    if ( n <= 0 || val < 0)
        return 0;

    if ( val == 0 )
        return 1;

    return change(coins, n, val-coins[n-1]) + change(coins, n-1, val);
    

}

int main(){

    int n;
    cin>>n;

    vector <int> coins (n);
    for ( int i = 0; i<n; i++ )
        cin>>coins[i];

    int val;
    cin>>val;    

    cout<<change(coins, n, val);

    return 0;

}