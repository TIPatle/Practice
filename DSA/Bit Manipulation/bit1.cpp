// Print the unique number in an array as all number in pair of two

#include <iostream>

using namespace std;

int main(){

    int arr[] = {2, 1, 2, 5, 6, 5, 7, 7, 6};
    int ans = 0;

    for ( int i = 0; i<9; i++ ){

        ans ^= arr[i];

    }

    cout<<ans<<endl;

    return 0;

}