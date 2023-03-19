#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

int main(){

    int n, m;
    cin>>n>>m;

    vector <vector<pair<int, int>>> adj(1e5);
    vector <bool> visited(1e5, 0);
    vector <int> parent(1e5);
    vector <int> dist(1e5, INT_MAX);

    for ( int i = 0; i<m; i++ ){

        int x, y, w;
        cin>>x>>y>>w;

        adj[x].push_back({w, y});
        adj[y].push_back({w, x});

    }

    int intial = 0;
    set <pair <int, int>> s;
    s.insert({0, intial});
    dist[intial] = 0;

    int mst = 0;

    while ( !s.empty() ){
        
        auto node = *(s.begin());
        s.erase(node);
        visited[node.second] = 1;

        cout<<node.second<<" "<<parent[node.second]<<" "<<node.first<<endl;
        
        mst += node.first;

        for ( auto it : adj[node.second] ){

            if ( visited[it.second] )
                continue;

            if ( dist[it.second] > it.second ){

                s.erase({dist[it.second], it.second});
                dist[it.second] = it.first;

                s.insert({dist[it.second], it.second});
                parent[it.second] = node.second;

            }
            
        }


    }

    cout<<mst<<endl;

    return 0;

}