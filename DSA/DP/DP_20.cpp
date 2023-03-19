#include <iostream>
#include <vector>

using namespace std;

vector <int> arr(1e5);

int main(){

    int n;
    cin>>n; 

    for ( int i = 0; i<n; i++)
        cin>>arr[i];

    vector <int> jump(1e5, 1e7);

    if ( arr[0] == 0 ){

        cout<<"Cannot Jump "<<endl;
        return -1;

    } 

    jump[0] = 0;
    for ( int i = 0; i<n; i++ ){

        for ( int j = 0; j<i; j++ ){

            if ( i <= j + arr[j] )
                jump[i] = min(jump[i], jump[j] + 1);

        }

    }

    cout<<jump[n-1]<<endl;

    return 0;

}