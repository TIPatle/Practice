#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> ans;

int ratMaze( vector<vector<int>> &arr, int x, int y, int n ){

    if ( x == n-1 && y == n-1 ){

        ans[x][y] = 1;
        return 1;

    }

    if ( x >= n || y >= n )
        return -10000;

    if ( arr[x][y] == 0 )
        return -10000;

    int ans1 = ratMaze(arr, x+1, y, n);
    int ans2 = ratMaze(arr, x, y+1, n);

    if ( ans1 > 0  )
        ans[x][y] = 1;

    if ( ans2 > 0 )
        ans[x][y] = 1;

    return max(max(ans1+1, ans2+1), -10000);


}

int main(){

    int n;
    cin>>n;

    vector<vector<int>> arr(n, vector<int> (n, 0));
    ans = arr;

    for ( int i = 0; i<n; i++ ){

        for ( int j = 0; j<n; j++ ){

            cin>>arr[i][j];

        }

    }

    cout<<endl<<endl;
    int length = ratMaze(arr, 0, 0, n);
    if ( length > 0 ){

        cout<<"The Length of the road is : "<< length<<endl;

        for ( auto &it : ans ){

            for ( auto &i : it )
                cout<<i<<" ";

            cout<<endl;

        }

    }

    return 0;

}