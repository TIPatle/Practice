#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector <vector<int>> adj;
vector <bool> visited;

stack <int> s;

void topologicalSort( int i ){

    visited[i] = 1;

    for ( auto it : adj[i] ){

        if ( !visited[it] )
            topologicalSort(it);

    }

    s.push(i);

}


int main(){

    int n, m;
    cin>>n>>m;

    adj = vector<vector<int>> (n+1);
    visited = vector <bool> (n+1);

    for ( int i = 0; i<m; i++ ){

        int x, y;
        cin>>x>>y;

        adj[x].push_back(y);

    }

    for ( int i = 0; i<=n; i++ )
        if ( !visited[i] )
            topologicalSort(i);

    while(!s.empty()){

        cout<<s.top()<<" ";
        s.pop();

    }




    return 0;

}