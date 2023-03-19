#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    cin>>n;

    vector <int> arr(n);

    for ( int i = 0; i<n; i++ )
        cin>>arr[i];

    int curr = 0;
    int maxi = 0;

    for ( int i = 0; i<n; i++ ){

        curr += arr[i];
        maxi = max(curr, maxi);

        if ( curr < 0 )
            curr = 0;

    }

    cout<<maxi<<endl;
    
    return 0;

}