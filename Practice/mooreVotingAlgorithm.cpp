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

class elecount{

    public:
        int count = 0;
        int ele = 0;

};

void ElementOccurenceNK( int arr[], int n, int k ){

    if ( n < 2 )
        return ;

    elecount temp[k];

    rep(i, 0, n){

        int j = 0;
        for ( j = 0; j<k; j++){

            if ( arr[i] == temp[j].ele ){
                
                temp[j].ele++;
                break;

            }

        }

        if ( j == k - 1 ){

            for ( j = 0; j<k; j++){

                if ( temp[j].count == 0 ){
                    
                    temp[j].ele = arr[i];
                    break;

                }

            }

        }

        if ( j == k-1 ){

            for ( j = 0; j<k; j++ ){

                temp[j].count--;

            }

        }


    }

    rep(i, 0, k){

        int count = 0;
        rep(j, 0, n){

            if ( temp[i].ele == arr[j] )
                count++;


        }
        
        if ( count > (n/k) )
            cout<<temp[i].ele<<" ";

    }

    cout<<endl;

}

int main(){
    
    int n,k;
    cin>>n>>k;

    int arr[n];
    rep(i, 0, n) cin>>arr[i];

    ElementOccurenceNK(arr,n, k-1);   

    return 0;

}