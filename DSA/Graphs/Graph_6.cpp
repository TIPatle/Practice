#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    
    int n, m;
    cin>>n>>m;

    vector <int> adj[n];
    int indeg[n] = {0};

    int x, y;
    for ( int i = 0; i<m; i++ ){

        //  x --> y

        cin>>x>>y;
        adj[x].push_back(y);
        indeg[y]++;

    }

    queue <int> q;

    for ( int i = 0; i<n; i++ ){

        if ( indeg[i] == 0 )
            q.push(i);

    }

    int cnt = 0;

    while ( !q.empty() ){

        cnt++;

        int node = q.front();
        q.pop();

        cout<<node<<" ";

        // node --> v/ it

        for ( auto it : adj[node] ){

            indeg[it]--;

            if ( indeg[it] == 0 )
                q.push(it); 

        }


    }

    return 0;

}