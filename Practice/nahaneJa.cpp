#include <bits/stdc++.h>

#define N 1e7
#define M 1e5

#define vi vector<int>
#define vii vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pii pair<int, int>

#define rep(i, a, b) for(int i = a; i<b; i++)
#define decrep(i, a, b) for ( int i = a; i>=b; i--)

using namespace std;



int main(){
    
    int t;
    cin>>t;

    while(t--){

        int n, k;
        cin>>n>>k;

        int arr[n];
        rep (i, 0, n )    
            cin>>arr[i];

        if ( n == 1){

            if ( arr[0] == k)
                cout<<"Yes"<<endl;

            else    
                cout<<"No"<<endl;

            continue;

        }

        bool found = 0;
        rep (i, 0, n-1){

            if ( arr[i] == k )
                found = 1;

        }

        if ( found )    
            cout<<"Yes"<<endl;

        else  
            cout<<"No"<<endl;

        
    }


    return 0;

}