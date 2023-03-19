#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n, m;
    cin>>n>>m;

    vector<vector<int>> vec(n+1, vector<int>(n+1, 0));

    for ( int i = 0; i<m; i++ ){

        int a, b;
        cin>>a>>b;

        vec[a][b] = 1;
        vec[b][a] = 1;

    }

    for ( int i = 1; i<n+1; i++ ){

        for ( int j = 1; j<n+1; j++ ){

            cout<<vec[i][j]<<" ";

        }

        cout<<endl;

    }

    return 0;
    
}