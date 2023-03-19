#include <iostream>

using namespace std;

int main(){

    int n;
    cin>>n;

    for ( int i = n; i>0; i-- ){

        for ( int j = n; j > n - i ; j-- )
            cout<<j<<" ";


        cout<<endl;

    }

    return 0;

}