#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n, m;
    cin>>n>>m;

    vector<int> a[n + 1];

    for ( int i = 0; i<m; i++ ){

        int x, y;
        cin>>x>>y;

        a[x].push_back(y);
        a[y].push_back(x);


    }

    int i = 0;

    for ( auto it : a ){

        cout<<i++<<"->";

        for ( auto itt : it )
            cout<<itt<<" ";

        cout<<"NULL"<<endl;

    }

    return 0;

}