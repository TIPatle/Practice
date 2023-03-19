// Bellman ford algorithm 

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, m;
    cin>>n>>m;

    vector<vector<int>> edges;
    vector<int> dist(n, 1e5);

    for ( int i = 0; i<m; i++ ){

        int x, y, w;
        cin>>x>>y>>w;

        edges.push_back({x, y, w});

    }

    int src;
    cin>>src;

    dist[src] = 0;

    for ( int i = 0; i<n-1; i++ ){

        for ( auto it : edges ){
            
            if ( dist[it[0]] + it[2] < dist[it[1]])
                dist[it[1]] = dist[it[0]] + it[2];

           //dist[it[1]] = min(dist[it[1]], dist[it[0]] + it[2]);

        }

    }

    for ( auto it : edges )
        if ( dist[it[0]] + it[2] < dist[it[1]])
            cout<<"Negative cycle Present"<<endl;

    for ( auto it : dist )
        cout<<it<<" ";

    return 0;

}