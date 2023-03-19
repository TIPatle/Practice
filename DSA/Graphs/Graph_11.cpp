#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector<int>> adj;
vector <int> color;
vector <bool> visited;

int main(){

    int n, m;
    cin>>n>>m;

    adj = vector<vector<int>> (n);
    color = vector<int> (n, -1);
    visited = vector <bool> (n, 0);

    for ( int i = 0; i<m; i++ ){

        int x, y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);

    }

    int intial;
    cin>>intial;

    queue <int> q;
    q.push(intial);
    visited[intial] = 1;
    color[intial] = 1;   // 1 ---> red & 0 ----> blue & -1 no color

    bool bipartite = 1;

    while (!q.empty()){

        int node = q.front();
        q.pop();

        for ( auto it : adj[node] ){

            if ( !visited[it] ){

                visited[it] = 1;
                q.push(it);
                color[it] = !color[node];

            }

            else if ( visited[it] && color[it] == color[node] ){

                bipartite = false;
                goto label;

            }

        }

    }

    label :

    if ( !bipartite )
        cout<<"Graph is not Bipartite "<<endl;

    else
        cout<<"Graph is Bipartite "<<endl;

    return 0;

}
