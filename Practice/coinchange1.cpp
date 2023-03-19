#include <bits/stdc++.h>

#define N 1e7
#define M 1e5

#define vi vector<int>
#define vii vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pii pair<int, int>

#define rep(i, a, b) for(int i = a; i<b; i++)
#define decrep(i, a, b) for ( int i = a; i>=b; i--)

using namespace std;

int possibleCombination(int coins[], int summ,  int n){

    if ( summ == 0 )
        return 1;

    if ( n == 0 )
        return 0;

    if ( summ >= coins[n-1] )
        return possibleCombination(coins, summ-coins[n-1], n) + possibleCombination(coins, summ, n-1);

    return possibleCombination(coins, summ, n-1);

}

int main(){
    
    int coins[] = {1, 2, 3};
    int sum = 5;
    int n = 3;

    cout<<possibleCombination(coins, sum, n);


    return 0;

}