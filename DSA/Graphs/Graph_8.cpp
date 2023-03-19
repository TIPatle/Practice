#include <iostream>
#include <vector>


using namespace std;

bool iscycle (int src, vector<vector<int>> adj, vector <bool> visited, vector <int> stack ){

    stack[src] = 1;

    if ( !visited[src] ){

        visited[src] = 1;

        for ( auto it : adj[src] ){

            if (stack[it])
                return true;

            if ( !visited[it] && iscycle(it, adj, visited, stack))
                return true;

        }

    }

    stack[src] = 0;

    return false;

}

int main(){

    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n);
    vector <bool> visited (n, 0);

    for ( int i = 0; i<m; i++ ){

        int x, y;
        cin>>x>>y;

        // x ----------> y
        adj[x].push_back(y);

    }

    bool cycle = 0;
    vector <int> stack(n, 0);

    for ( int i = 0; i<n; i++ ){

        if ( !visited[i] && iscycle(i, adj, visited, stack) )
            cycle = 1;

    }

    if ( cycle )
        cout<<"cycle is present "<<endl;

    else 
        cout<<"cycle is not present "<<endl;



    return 0;
    
}