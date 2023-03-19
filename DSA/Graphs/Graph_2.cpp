// BFS Graph Implentation :- another way

#include <iostream>
#include <queue>

using namespace std;

int main(){

    int n, m;
    cin>>n>>m;

    int a[n][n] = {0};
    int visited[n] = {0};

    for ( int i = 0; i<m; i++ ){

        int x, y;
        cin>>x>>y;

        a[x][y] = 1;
        a[y][x] = 1;

    }

    int intial = 0;
    
    queue <int> q;
    cout <<intial<<" ";
    q.push(intial);
    visited[intial] = 1;

    while ( !q.empty() ){

        int node = q.front();
        q.pop();

        for ( int i = 0; i<n; i++ ){

            if ( a[node][i] == 1 && visited[i] == 0 ){

                visited[i] = 1;
                q.push(i);
                cout<<i<<" ";

            }

        }

    }

    return 0;

}
