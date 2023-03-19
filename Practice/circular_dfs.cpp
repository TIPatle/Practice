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
vi vis(M, 0);

bool iscircular( int i, int parent){

    vis[i] = 1;

    for ( auto it : adj[i] ){

        if ( vis[it] && it != parent && parent != -1 )
            return true;

        else {

            vis[it] = 1;

            if (iscircular(it, i))
                return true;

        }

    }

    return false;
    

}

int main(){
    
    int n, m;
    cin>>n>>m;

    rep(i, 1, m+1 ){

        int x, y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);

    }

    bool circular = 0;
    rep(i, 1, n+1){

        if ( !vis[i] ){
    
            if(iscircular(i, -1)){ 

                circular = 1;

            }

        }

        cout<<"o "<<endl;

    }

    cout<<circular<<endl;


    return 0;

}