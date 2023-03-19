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
    
    int n;
    cin>>n;

    int arr[n];
    rep(i, 0, n)
        cin>>arr[i];
    /*
    int nIndex = 0;
    rep(i, 0, n){

        if ( arr[i] < 0 ){

            swap(arr[nIndex], arr[i]);
            nIndex++;

        }

    }
    */

    int negative = 0;
    int positive = n - 1;

    while ( positive >= negative ){

        if ( (arr[positive] <  0 || arr[positive] > 0) && arr[negative] < 0 )
            negative++;

        else if ( arr[positive] > 0 && (arr[negative] < 0 || arr[negative] > 0))
            positive--;

        else if ( arr[positive] < 0 && arr[negative] > 0  ){

            swap(arr[positive], arr[negative]);
            negative++;
            positive--;

        }

   

    }

    rep(i, 0, n)
        cout<<arr[i]<<" ";


    return 0;

}