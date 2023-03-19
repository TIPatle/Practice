#include<iostream>
#include<vector>

using namespace std;

bool isSafe( vector<vector<int>> &arr, int x, int y, int n){

    for ( int i = 0; i<x; i++ ){

        if ( arr[i][y] == 1 )
            return false;

    }

    int i = x;
    int j = y;

    while( i >= 0 && j >= 0 ){

        if ( arr[i][j] == 1 )
            return false;

        i--;
        j--;

    }

    i = x;
    j = y;

    while( i >= 0 && j < n ){

        if ( arr[i][j] == 1)
            return false;

        i--;
        j++;

    }

    return true;

}

bool nqueen( vector<vector<int>> &arr, int x, int n ){

    if ( x >= n )
        return true;

    for ( int col = 0; col<n; col++ ){

        if ( isSafe(arr, x, col, n)){

            arr[x][col] = 1;
            
            if ( nqueen(arr, x+1, n))
                return true;

            else
                arr[x][col] = 0;

        }

    }

    return false;

}

int main(){

    int n;
    cin>>n;

    vector<vector<int>> arr(n, vector<int> (n, 0));

    nqueen(arr, 0, n);
    
    for ( auto &it : arr ){

        for ( auto &i : it )
            cout<<i<<" ";

        cout<<endl;

    }


    return 0;

}