#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 2;
bool visited[N] = {0};
vector <int> adj[N];

void dfs (int node ){

    // preorder 

    visited[node] = 1;
    //cout<<node<<" ";  // -- here it will print preorder

    // inorder 

    vector <int> :: iterator it;

    for ( it = adj[node].begin(); it != adj[node].end(); it++ ){

        if ( !visited[*it] )
            dfs(*it);

    }

    // postorder
    cout<<node<<" ";  // here it will print Postorder 

}

int main(){

    int n, m;
    cin>>n>>m;

    int x, y;
    for ( int i = 0; i<m; i++ ){

        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);

    }

    dfs (1);

    return 0;

}