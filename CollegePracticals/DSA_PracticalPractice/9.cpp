#include <iostream>
#include <vector>
#include <queue>

#define N 1e4

using namespace std;

vector <vector<pair<int, int>>> adj(N);
vector <bool> visited(N);

int minimumCost( int hdq ){

    priority_queue < pair<int, int> , vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push({0, hdq});

    int cost = 0;

    while ( !pq.empty() ){

        auto node = pq.top();
        pq.pop();

        if ( !visited[node.second] ){

            cost += node.first;
            visited[node.second] = 1;

            cout<<node.second<<"---->";

        }

        for ( auto it : adj[node.second] ){

            if ( !visited[it.first] )
                pq.push({it.second, it.first});

        }

    }

    cout<<"End"<<endl;

    return cost;

}

void insert( int m ){

    for ( int i = 0; i<m; i++ ){

        int x, y, length;
        cin>>x>>y>>length;

        adj[x].push_back({y, length});
        adj[y].push_back({x, length});

    }

}

int main(){

    cout<<"Enter the number of offices do we have :- ";
    int n;
    cin>>n;

    cout<<"Enter the numbers routes possible :- ";
    int m;
    cin>>m;

    insert(m);

    int hdq;
    cin>>hdq;

    cout<<minimumCost(hdq)<<endl;

    return 0;
}
