#include <iostream>
#include <stack>

using namespace std;

int main(){

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

    stack <int> s;

    int intial = 6;
    cout<<intial<<" ";

    visited[intial] = 1;
    s.push(intial);

    while ( !s.empty() ){

        int node = s.top();
        s.pop();

        for ( int i = 0; i<n; i++ ){

            if ( a[node][i] == 1 && visited[i] == 0 ){

                s.push(i);
                visited[i] = 1;
                cout<<i<<" ";

            }

        }

    }



    return 0;

}