#include <iostream>
#include <climits>
#include <vector>
#define INF int(1e5)

using namespace std;

int main(){

    int n, m;
     n = m = 4;

    vector <vector<int>> dist = {{0, 5, INF, 10},
                                 {INF, 0, 3, INF}, 
                                 {INF, INF, 0, 1},
                                 {INF, INF, INF, 0}};


    for ( int k = 0; k<n; k++ ){

        for ( int i = 0; i< n; i++ ){

            for ( int j = 0; j<n; j++ ){

                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);

            }

        }

    }

    for ( int i = 0; i < n; i++ ){

        for ( int j = 0; j < n; j++ ){

            if ( dist[i][j] != 1e5 )
                cout<<dist[i][j]<<" ";

            else 
                cout<<"INF"<<" ";

        }

        cout<<endl;

    }

    return 0;
}