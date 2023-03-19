#include <iostream> 
#include <vector>
#include <queue>

using namespace std;

int main(){

    cout<<"Enter the number of cities :- ";
    int n;
    cin>>n;

    vector <vector<pair<int, int>>> adj(n+1);

    int m;
    cout<<"Enter the number of flight path between cites :- ";
    cin>>m;

    for ( int i = 1; i<=m; i++ ){

        int x, y, time;
        cin>>x>>y>>time;

        adj[x].push_back({y, time});

    }

    vector <int> visited(n+1, 0);
    int conComp = 0;

    for ( int i = 1; i<=n; i++ ){

        if ( !visited[i] ){

            queue <int> q;
            q.push(i);
            visited[i] = 1;

            while(!q.empty()){

                int node = q.front();
                q.pop();

                for ( auto it : adj[node] ){

                    if ( !visited[it.first] ){

                        visited[it.first] = 1;
                        q.push(i);

                    }

                }

            }

            conComp++;

        }


    }

    cout<<endl;

    if ( conComp > 1 )
        cout<<"All the cities not interconnected "<<endl;

    else 
        cout<<"All the citied are interconnected "<<endl<<endl;

    for ( int i = 1; i<=n; i++ ){

        for ( auto it : adj[i] )
            cout<<"City "<<i<<" to City "<<it.first<<" will take "<<it.second<<" hrs."<<endl;

    }

    

    return 0;

}