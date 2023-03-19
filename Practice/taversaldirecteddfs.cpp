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

vii adj(M);
vi vis(M);

void dfs ( int i ){

    if ( !vis[i] ){

        vis[i] = 1;
        cout<<i<<" ";

        for ( auto it : adj[i] )
            dfs(it);

    }

}

int main(){
    
    int n, m;
    cin>>n>>m;

    rep(i, 1, m+1){

        int x, y;
        cin>>x>>y;

        adj[x].push_back(y);

    }

    rep(i, 1, n+1){

        if ( !vis[i] ){
            
            dfs(i);
            cout<<endl;

        }

    }

    return 0;

}