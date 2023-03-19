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
vi dfsrec;
vi v(M);

vi ans ;

void dfs(int i){

    if ( !v[i] ){

        v[i] = 1;
        ans.push_back(i);

        for ( auto it : adj[i] )
            dfs(it);

    }


}

int main(){
    
    int n, m;
    cin>>n>>m;

    rep(i, 0, m){

        int x, y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);

    }

    int connected = 0;
    rep(i, 1, n+1){

        if (!v[i]){
 
            dfs(i);
            connected++;

        }

    }

    rep(i, 0, n)
        cout<<ans[i]<<" ";


    return 0;

}