#include <iostream>
#include <vector>

using namespace std;

// Brute force Approach Having time complexity of O(N*N) and Space Complexity is O(N)

int main(){

    int n, k;
    cin>>n>>k;

    int arr[n];
    for ( int i = 0; i<n; i++ )
        cin>>arr[i];

    int leastLimit = n / k;
    
    vector <int> ans;
    for ( int i = 0; i<n; i++ ){

        int k = 0; 
        for ( int j = 0; j<n; j++ ){

            if ( arr[i] == arr[j])
                k++;

        }

        bool flag = 0;
        if ( k > leastLimit ){

            if ( ans.empty() )
                ans.push_back(arr[i]);

            for ( auto it : ans ){

                if ( it == arr[i] ){

                    flag = 0;
                    break;

                }

                flag = 1;

            }


        }

        if ( flag )
            ans.push_back(arr[i]);

    }

    for ( auto it : ans )
        cout<<it<<" ";

    return 0;

}