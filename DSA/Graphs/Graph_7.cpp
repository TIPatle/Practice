#include <iostream>
#include <vector>

using namespace std;

bool iscycle(int src, vector<vector<int>> &adj, vector <bool> &visited, int parent){

    visited[src] = 1;

    for ( auto it : adj[src] ){

        if ( it != parent ){

            if ( visited[it] )
                return true;

            if ( !visited[it] && iscycle(it, adj, visited, src))
                return true;


        }

    }

    return false;

}

int main(){

    int n, m;
    cin>>n>>m;

    vector <vector <int>> adj(n);
    vector <bool> visited(n, 0);

    for ( int i = 0; i<m; i++ ){

        int x, y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);

    }

    bool cycle = false;

    for ( int i = 0; i<n; i++ ){

        if ( !visited[i] && iscycle (i, adj, visited, -1))
            cycle = true;

    }

    if ( cycle )
        cout<<"Cycle is present"<<endl;

    else 
        cout<<"cycle is not present"<<endl;


    return 0;
    
}