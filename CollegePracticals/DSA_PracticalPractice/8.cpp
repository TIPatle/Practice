#include <iostream>
#include <vector>
#define N 1e4

using namespace std;

vector <vector<pair<char, float>>> adj(N);

int main(){

    cout<<"Enter the number of cities :- ";
    int n;
    cin>>n;

    cout<<"Enter the number of routes :- ";
    int m;
    cin>>m;

    for ( int i = 0; i<m; i++ ){

        cout<<endl;

        char x, y;
        float time;

        cout<<"Enter Source :- ";
        cin>>x;

        cout<<"Enter Destination :- ";
        cin>>y;
        cout<<"Enter time taken :- ";
        cin>>time ; 
        
        // x ----> y time x upper case only

        adj[x - 'A'].push_back({y, time});

    }

    for ( int i = 0; i<n; i++ ){

        for ( auto it : adj[i] )
            cout<<char('A' + i)<<" ---> "<<it.first<<"\ttime :- "<<it.second<<" hrs" <<endl;


    }


}