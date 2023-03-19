#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n, k;
        cin>>n>>k;

        if ( !n%4 ){

            if ( k )
                cout<<"ON"<<endl;

            else
                cout<<"OFF"<<endl;

        }

        else{

            if ( k )
                cout<<"Ambiguous"<<endl;

            else
                cout<<"ON"<<endl;

        }

    }

    return 0;
}