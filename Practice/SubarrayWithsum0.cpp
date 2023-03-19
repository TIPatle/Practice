#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];
    for ( int i = 0; i<n; i++ )
        cin>>arr[i];

    // Brute force approach  takes O(n*n)
    /*
    int start = -1;
    int end = -1;
    for ( int i = 0; i<n; i++ ){

        int sum = arr[i];
        for ( int j = i+1; j<n; j++ ){

            sum += arr[j];

            if ( sum == 0 ){

                start = i;
                end = j;

            }

        }

    }

    */

    

    return 0;

}