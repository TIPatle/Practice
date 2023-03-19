// BFS Implementation

#include <iostream>
#include <queue>

using namespace std;



int main(){

    queue <int> q; 

    int n = 7;

    int visited[n] = {0};
    int a[n][n] = {
                    {0, 1, 1, 1, 0, 0, 0},
                    {1, 0, 1, 0, 0, 0, 0},
                    {1, 1, 0, 1, 1, 0, 0},
                    {1, 0, 1, 0, 1, 0, 0},
                    {0, 0, 1, 1, 0, 1, 1},
                    {0, 0, 0, 0, 1, 0, 0},
                    {0, 0, 0, 0, 1, 0, 0}
    };


    int intial = 0;
    
    cout<<intial<<" ";
    q.push(intial);
    visited[intial] =  1;

    while ( !q.empty() ){

        int node = q.front();
        q.pop();

        for ( int i = 0; i<n; i++ ){

            if ( a[node][i] == 1 && visited[i] == 0 ){

                cout<<i<<" ";
                q.push(i);
                visited[i] = 1;

            }

        }

    }


    return 0;

}