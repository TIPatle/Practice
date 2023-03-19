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



int main(){

    int n, m;
    cin>>n>>m;

    vii a(n+1, vector<int> (m+1, 0));
    rep(i, 1, n+1)
        rep(j, 1, m+1)
            cin>>a[i][j];

    rep(i, 1, n+1)
        rep(j, 1, m+1)
            cout<<a[i][j]<<" ";

    vii adj(n+1);

    rep(i, 1, n+1){

        int x, y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);

    }

    for ( auto i : adj ){

        for( auto it : i )
            cout<<it<<" ";

        cout<<endl;

    }

    return 0;

}