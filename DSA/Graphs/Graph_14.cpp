#include <iostream>
#include <vector>
#include <set>
#include <climits>

#define N 1e5

using namespace std;

vector<vector<pair<int, int>>> adj(N);
vector <bool> visited(N);
vector <int> dist(N);
vector <int> parent(N);

int n,m;
int cost = 0;

void prims( int source){

    for (int i = 0; i<n; i++ )
        dist[i] = INT_MAX;

    set<pair<int, int>> s;
    dist[source] = 0;  
    s.insert({0, source});

    while ( !s.empty() ){

        auto x = *(s.begin());
        s.erase(x);

        visited[x.second] = 1;

        int u = x.second;
        int v = parent[x.second];
        int w = x.first;

        cout<<u<<" "<<v<<" "<<w<<endl;
        cost += w;

        for ( auto it : adj[x.second] ){

            if ( visited[it.first] )
                continue;
            
            if ( dist[it.first] > it.second ){

                s.erase({dist[it.first], it.first});
                dist[it.first] = it.second;

                s.insert({dist[it.first], it.first});
                parent[it.first] = x.second;

            }

        }

    }

    cout<<cost<<endl;

}

int main(){

    
    cin>>n>>m;

    for ( int i = 0; i<m; i++ ){

        int x, y, w;
        cin>>x>>y>>w;

        adj[x].push_back({y, w });
        adj[y].push_back({x, w});

    }

    prims(0);

    return 0;

}