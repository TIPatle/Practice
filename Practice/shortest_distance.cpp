#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector<pair<int, int>>> adj(100);
vector <int> dist;

void shortestDistance( int node ){  //O(n + e)

    dist = vector<int> (100, 1e9);
    dist[node] = 0;
    queue <int> q;
    q.push(node);

    while ( !q.empty() ){

        int element = q.front();
        int distance = dist[element];
        q.pop();

        for ( auto it : adj[element] ){

            if ( dist[it.first] > distance + it.second ){

                dist[it.first] = distance + it.second;
                q.push(it.first);

            }

        }


    }

}

int main(){

    int n, m;
    cin>>n>>m;

    for ( int i = 0; i<m; i++ ){

        int u, v, d;
        cin>>u>>v>>d;

        adj[u].push_back({v, d});
        adj[v].push_back({u, d});

    }

    for ( int i = 0; i<n; i++ ){ // O(n * (n + e )) == O(n*n*n) if ( e = n*n)

        shortestDistance(i);
        cout<<"The Distance from starting node "<<i<<" :- "<<endl;
        for ( int j = 0; j<n; j++ )
            cout<<dist[j]<<" ";

        cout<<endl;

    }


    return 0;

}