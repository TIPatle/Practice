// Find two number which appears once.
// Find Xor all number
// After finding xor find first set bit pos and according to that seperate the number
// Take xor of set1 and set2 and the xor of sets is our answer
#include <iostream>

using namespace std;

int* uniqueNo( int arr[], int n ){

    int bit = 0;
    for ( int i = 0; i<n; i++ )
        bit = bit ^ arr[i];

    int count = 0;
    while ( bit ){

        if ( bit & 1 )
            break;

        bit = bit >> 1;
        count++;

    }

    int x = 0, y = 0, mask = 1 << count;
    for ( int i = 0; i<n; i++){

        if ( arr[i] & mask )
            x = x ^ arr[i];

        else 
            y = y ^ arr[i];

    }

    int* ans = new int[2];
    ans[0] = x;
    ans[1] = y;

    return ans;

}

int main(){

    int arr[] = {1, 2, 3, 0, 2, 5, 1, 3};
    int n = 8;

    int* ans = uniqueNo(arr, n);

    cout<<ans[0]<<" "<<ans[1]<<endl;

    return 0;

}