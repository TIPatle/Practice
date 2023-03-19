#include <iostream>
#include <vector>

using namespace std;

int main(){

    cout<<"Enter no of cities :- ";
    int n;
    cin>>n;

    cout<<"Enter the no of the route available :- ";
    int m;
    cin>>m;

    vector <vector <pair<int, int>>> adj(n+1);

    cout<<endl<<"Enter the city from 1 to "<<n<<" :- "<<endl;

    for ( int i = 0; i<m; i++ ){

        int x, y, t;
        cin>>x>>y>>t;   // x --> y  t-->time taken to reach y from x

        adj[x].push_back({y,t});

    }

    // Printing adjancency list 
    for ( int i = 0; i<n; i++){

        for ( auto it : adj[i] ) 
            cout<<"City "<<i<<"--->"<<"City "<<it.first<<"\tTime :- "<<it.second<<" hrs"<<endl;

    }

    return 0;

}