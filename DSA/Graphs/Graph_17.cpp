// dijkstra algorithm

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, m;
    cin>>n>>m;

    vector <vector<pair<int, int>>> adj(n+1);
    vector <bool> visited (n+1, 0);
    vector <int> dist (n+1, INT_MAX);
    vector <int> parent(n+1);

    for ( int i = 0; i<m; i++ ){

        int x, y, w;
        cin>>x>>y>>w;

        adj[x].push_back({y, w});
        adj[y].push_back({x, w});

    }

    set <pair<int, int>> s;
    int src;
    cin>>src;
    dist[src] = 0;
    s.insert({0, src});

    int cost = 0;

    while (!s.empty()){

        auto node = *(s.begin());
        s.erase(node);
        visited[node.second] = 1;

        cost += node.first;

        for ( auto it : adj[node.second] ){

            if ( visited[it.first] )
                continue;

            if ( dist[it.first] > dist[node.second] + it.second ){

                s.erase({dist[it.first], it.first});
                dist[it.first] = dist[node.second] + it.second;

                s.insert({dist[it.first], it.first});
                parent[it.first] = node.second;

            }

        }

    }

    for ( auto it = dist.begin() +1; it != dist.end(); it++ )
        cout<<*it<<" ";

    cout<<endl;

    return 0;

}