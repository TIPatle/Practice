#include <iostream>
#include <vector>

using namespace std;

void change ( vector<vector<char>> &v, int i , int j){

    v[i][j] = '*';

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    for ( int k = 0; k<4; k++ ){

        int x = i + dx[k];
        int y = j + dy[k];

        if ( x < v.size() && y < v[0].size() && x>=0 && y>= 0 && v[x][y] == 'O'){
                change(v, x, y);

        }

    }

}

int main(){

    int n, m;
    cin>>n>>m;

    vector<vector<char>> v(n, vector<char>(m));

    for ( int i = 0; i<n; i++ ){

        for ( int j = 0; j<m; j++ ){

            cin>>v[i][j];

        }

    }    

    for ( int i = 0; i<n; i++ ){

        for ( int j = 0; j<m; j++ ){

            if ( i == 0 || j == 0 || i == n-1 || j == m-1 )
                if ( v[i][j] == 'O' )
                    change(v, i, j);  // to *

        }
        
    }

    for ( int i = 0; i<n; i++ ){

        for ( int j = 0; j<m; j++ ){

            if ( v[i][j] == 'O' )
                v[i][j] = 'X';

        }

    }

    for ( int i = 0; i<n; i++ ){

        for ( int j = 0; j<m; j++ ){

            if ( v[i][j] == '*' )
                v[i][j] = 'O';

        }

    }

    for ( int i = 0; i<n; i++ ){

        for ( int j = 0; j<m; j++ ){

            cout<<v[i][j]<<" ";

        }

        cout<<endl;

    }

    return 0;

}