#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    cin>>n;

    vector <int> arr(n);

    for ( int i = 0; i<n; i++ )
        cin>>arr[i];

    vector<int> forward(n+1, 1);
    vector<int> backward(n+1, 1);

    for ( int i = 1; i<n; i++ ){

        for ( int j = 1; j<= i; j++ )
            if ( arr[i] > arr[j] )
                forward[i] = max(forward[i], 1 + forward[j]);

    }

    for ( int i = 1; i<n; i++ ){

        for ( int j = i; j< n; j++)
            if ( arr[i] > arr[j] )
                backward[i] = max(backward[i], 1 + backward[j-1]);

    }

    int ans = 0;
    for ( int i = 0; i<n; i++ )
        ans = max(ans, 1 + forward[i] + backward[i]);

    cout<<ans<<endl;

    return 0;

}