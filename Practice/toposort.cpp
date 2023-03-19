#include <iostream>
#include <vector> 
#include <stack>

using namespace std;

vector<vector<int>> adj;
vector<int> visited;

stack <int> s;

void toporder( int node ){

    if ( visited[node] )
        return;

    visited[node] = 1;

    for ( auto it : adj[node] )
        if ( !visited[it] )
            toporder(it);

    s.push(node);

}

int main(){

    int n, m;
    cin>>n>>m;
    
    adj = vector<vector<int>>(n+1);
    visited = vector <int>(n+1, 0);

    for ( int i = 0; i<m; i++ ){

        int x, y;
        cin>>x>>y;

        adj[x].push_back(y);

    }

    for ( int i = 0; i<=n; i++ ){

        if ( !visited[i])
            toporder(i);

    }

    while( !s.empty() ){

        cout<<s.top()<<" ";
        s.pop();

    }

    return 0;

}