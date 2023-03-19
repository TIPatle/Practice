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

    vii adj(n+1);
    rep(i, 0, m){

        int x, y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);

    }

    vi dfs;
    vi v(n+1, 0);
    int connectedcomp = 0;

    rep(i, 1, n+1){  // To include all connected component of a graph

        if (!v[i]){
            // dfs start here which is not a optimized code;
            stack <int> s;
            s.push(i);
            v[i] = 1;

            while ( !s.empty() ){

                int node = s.top();
                dfs.push_back(node);
                s.pop();

                for ( auto it : adj[node] ){

                    if ( !v[it] ){

                        s.push(it);
                        v[it] = 1;

                    }

                }

            }


        }

        connectedcomp++;

    }

    cout<<"There are "<<connectedcomp<<" connected component in a graph ."<<endl;
    for ( auto it :  dfs ){

        cout<<it<<" ";

    }


    return 0;

}