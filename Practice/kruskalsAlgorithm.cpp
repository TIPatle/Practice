#include <iostream>
#include <vector>
#include <queue> 

using namespace std;

vector <vector<pair<int, int>>> adj;
vector <bool> visited;

int MST( int n ){

    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    
    for ( int i = 0; i<= n; i++  )
        for ( auto it : adj[i]  )
            q.push({it.second, it.first});

    int ans = 0;
    while (!q.empty()){

        pair<int, int> node = q.top();
        q.pop();

        if ( !visited[node.second] ){

            ans += node.first;
            visited[node.second] = 1;

        }

    }

    return ans;
    

}

int main(){

    int n, m;
    cin>>n>>m;

    adj = vector <vector<pair<int, int>>> (n+1);
    visited  = vector <bool> (n+1);

    for ( int i = 0; i<m; i++ ){

        int x, y, w;
        cin>>x>>y>>w;

        adj[x].push_back({y, w});
        adj[y].push_back({x, w});

    }

    cout<<MST(n)<<endl;

    return 0;

}
