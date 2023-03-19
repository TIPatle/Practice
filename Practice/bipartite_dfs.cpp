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
vi color(M, -1);

bool isbipart( int i ){

    if ( color[i] == -1 )
        color[i] = -1;

    for ( auto it : adj[i] ){

        if ( color[it] == -1 ){

            color[it] = !color[i];
            isbipart(it);

        }

        else if ( color[it] == color[i] )
            return false;

    }

    return true;

}

bool isbipartite(int i, int col ){

    bool ans = true;

    if ( color[i] == -1 ){
    
        color[i] = col;

        for ( auto it : adj[i] ){

            if (isbipartite(it, !col))
                ans = ans & true;

            else 
                ans = ans & false;

        }

    }

    else if ( color[i] != col )
        ans = ans & false;

    return ans;

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

    rep(i, 1, n+1){

        if ( color[i] == -1 ){

            if(isbipartite(i, 0))
                cout<<"Graph with starting with node "<<i<<" is Bipartite.."<<endl;

            else 
                cout<<"Graph with starting with node "<<i<<" is not Bipartite.."<<endl;

        }

    }


    return 0;

}
