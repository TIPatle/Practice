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
vi v(M);
vi parent(M);

bool iscircular( int i ){

    queue<int> q;
    q.push(i);
    v[i] = 1;

    while (!q.empty()){

        int node = q.front();
        q.pop();
        parent[node] = -1;

        for ( auto it : adj[node] ){

            if ( !v[it] ){

                q.push(it);
                v[it] = 1;
                parent[it] = node;

            }

            
        }

    }

    return false;

}

int main(){
    
    int n, m;
    cin>>n>>m;

    rep(i, 1, m+1){

        int x, y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);

    }

    int connected = 0;
    bool circu = 0;
    rep(i, 1, n+1){
        
        if ( !v[i] )
            circu = iscircular(i) || circu;


    }

    cout<<circu<<endl;


    return 0;

}