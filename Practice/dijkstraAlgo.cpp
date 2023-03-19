#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector <vector<pair<int, int>>> adj;
vector <bool> visited;
vector <int> dist;

void findDist( int node ){

    priority_queue <pair<int, int>, vector<pair<int, int>> , greater <pair<int, int>> > q;
    q.push({0, node});

    dist[node] = 0;

    while( !q.empty() ){

        pair<int, int> n = q.top();
        q.pop();

        for ( auto it : adj[n.second]){

            int d = it .first + n.first;

            if ( dist[it.second] >  d ){

                dist[it.second] = d;
                q.push({d, it.second});

            }

        }


    }

}

int main(){

    int n, m;
    cin>>n>>m;

    adj = vector<vector<pair<int, int>>> (n+1);
    visited = vector <bool> (n+1, 0);
    dist = vector<int> (n+1, INT_MAX);

    for ( int  i = 0 ; i<m; i++ ){

        int x, y, w;
        cin>>x>>y>>w;

        adj[x].push_back({w, y});
        adj[y].push_back({w, x});

    }

    int node;
    cin>>node;

    findDist( node );

    for ( auto it : dist )
        cout<<it<<" ";

    return 0;

}