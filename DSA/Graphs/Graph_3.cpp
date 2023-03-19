#include <iostream>

using namespace std;

const int n = 7;
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

void dfs (int intial ){

    cout<<intial<<" ";
    visited[intial] = 1;

    for ( int j = 0; j<n; j++ ){

        if ( a[intial][j] == 1 && visited[j] == 0 )
            dfs(j);

    }


}

int main(){

    dfs(6);

    return 0;

}