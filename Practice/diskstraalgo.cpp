#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector<int>> dist;
vector <vector<pair<int, int>>> adj;

void findDist( int node, int i ){

    priority_queue <pair<int, int>, vector<pair<int, int>> , greater <pair<int, int>> > q;
    q.push({0, node});

    dist[i][node] = 0;

    while( !q.empty() ){

        auto vertex = q.top();
        q.pop();

        for ( auto it : adj[node] ){

            int d = it.second + vertex.first;

            if ( dist[i][it.first] > d ){

                dist[i][it.first]  = d;
                q.push({d, it.first });

            }

        }


    }


}

int main(){

    int n, m;
    cin>>n>>m;

    adj = vector<vector<pair<int, int>>>(n + 1);
    dist = vector<vector<int>>(n + 1, vector<int>(n+1, 1e9));

    for ( int i = 0; i<m; i++ ){

        int x, y, w;
        cin>>x>>y>>w;

        adj[x].push_back({y, w});
        adj[y].push_back({x, w});

    }

    for ( int i = 0; i<=n; i++ )
        findDist( 1, i);

    for ( auto it : dist ){

        for ( auto i : it   )
            cout<<i<<" ";

        cout<<endl;
    }


    return 0;

}