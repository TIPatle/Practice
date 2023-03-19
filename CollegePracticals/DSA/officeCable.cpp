#include <iostream>
#include <vector>
#include <queue>

#define N int(1e3)

using namespace std;

vector <vector<pair<int, int>>> adj(N);
vector <bool> visited(N);

int minimumCost ( int hdq ){

    priority_queue <pair<int, int>, vector<pair<int, int>>  ,greater<pair<int, int>> > pq;
    pq.push({0, hdq});

    int cost = 0;

    while ( !pq.empty() ){

        auto node = pq.top();
        pq.pop();

        if( !visited[node.second] ){

            visited[node.second] = 1;
            cost += node.first;

        }

        for ( auto it : adj[node.second] ){
            
            if ( !visited[it.first])
                pq.push({it.second, it.first});

        }

    }

    return cost;

}


int main(){

    cout<<"Enter Number of Offices :- ";
    int n;
    cin>>n;

    int m;
    cout<<"Enter all Possible connection can be made between office with cost :- ";
    cin>>m;

    for ( int i = 0; i<m; i++ ){

        int x, y, z;
        cin>>x>>y>>z;   

        // Bidirectional edge as we can go either way no problem

        adj[x].push_back({y, z});
        adj[y].push_back({x, z}); 

    }

    cout<<"Select the Main HeadQuarter of Company :- ";
    int hdq; 
    cin>>hdq;

    cout<<minimumCost(hdq)<<endl;

    return 0;

}