#include <bits/stdc++.h>

#define N 1e7
#define M 1e5

#define vi vector<int>
#define vii vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pii pair<int, int>

#define rep(i, a, b) for(int i = a; i<b; i++)
#define decrep(i, a, b) for ( int i = a; i>=b; i--)

using namespace std;



int main(){
    
    int n, m;
    cin>>n>>m;

    // Created a adjacenty list 
    vii adj(n+1);
    for ( int i = 0; i<m; i++){

        int x, y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);

    }

    vii bst(n+1);
    int connectedcount = 0;
    vi visited(n+1, 0);
    for ( int i = 1; i<=n; i++ ){

        if ( !visited[i] ){
            
            queue <int> q;
            q.push(i);
            visited[i] = 1;
            
            cout<<connectedcount<<endl;

            while (!q.empty()){

                int node = q.front();
                bst[connectedcount].push_back(node);
                q.pop();

                for ( auto it : adj[node])
                    if ( !visited[it] ){

                        q.push(it);
                        visited[it] = 1;

                    }

            }

            connectedcount++;

        }

    }

    cout<<"There are "<<connectedcount<<" connected component in a graph ."<<endl;
    for ( auto i : bst ){

        for ( auto it : i){

            cout<<it<<" ";

        }

        cout<<endl;

    }


    return 0;

}