#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector<int>> adj;
vector <bool> visited;
vector <int> indegree;
vector <int> ans;

void indeg(int n){

    for ( int i = 0; i<=n; i++ ){

        for ( auto it : adj[i] )
            indegree[it]++;

    }

}

void topological( int n ){

    queue <int> q;

    for ( int i = 0; i<=n; i++){

        if (!indegree[i]){

            q.push(i);
            visited[i] = 1;

        } 

    }
    

    while ( !q.empty() ){

        int node = q.front();
        q.pop();

        ans.push_back(node);

        for ( auto it : adj[node] ){

            if ( !visited[it] && ( indegree[it] - 1 == 0 || indegree[it] == 0) ){

                visited[it] = 1;
                q.push(it);

            }

            else 
                indegree[it] --;

        }

    }

}

int main(){

    int n, m;
    cin>>n>>m;

    adj = vector <vector<int>> (n+1);
    visited = vector<bool> (n+1, 0);
    indegree = vector<int> (n+1, 0);

    for ( int i = 0; i<m; i++ ){

        int x, y;
        cin>>x>>y;

        adj[x].push_back(y);

    }

    indeg(n);
    topological(n);

    for ( auto it : ans )
        cout<<it<<" ";
    

    return 0; 

}