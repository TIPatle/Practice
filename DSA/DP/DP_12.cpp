#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    cin>>n;

    vector <int> arr(n);
    for ( int i = 0; i<n; i++ ) 
        cin>>arr[i];

    vector <int> dp(n+1, 1);

    int ans = 0;
    for ( int i = 1; i<n; i++){

        for ( int j = 0; j<i; j++){

            if ( arr[i] > arr[j] )
                dp[i] = max(dp[i], 1 + dp[j]);

        }

        ans = max(dp[i], ans);

    }

    cout<<ans<<endl;

    return 0;

}