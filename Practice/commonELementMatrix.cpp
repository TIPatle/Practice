#include <bits/stdc++.h>

#define N 1e3
#define M 1e3

#define vi vector<int>
#define vii vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pii pair<int, int>

#define rep(i, a, b) for(int i = a; i<b; i++)
#define decrep(i, a, b) for ( int i = a; i>=b; i--)

using namespace std;

void common( vii matrix, int n, int m ){

    unordered_map <int, int> map;

    rep(i, 0, n){

        unordered_map<int, bool> check;

        rep(j, 0, m){

            if ( check[matrix[i][j]] == 1 )
                continue;

            map[ matrix[i][j] ]++;
            check[matrix[i][j]] = 1;

        }

    }

    for ( auto it : map ){

        if ( it.second == n )
            cout<<it.first<<" ";

    }

}

int main(){
    
    int n, m;
    cin>>n>>m;

    vii matrix(n, vi(m, 0));
    rep(i, 0, n){

        rep(j, 0, m){

            cin>>matrix[i][j];

        }

    }

    common(matrix, n, m);

    return 0;

}