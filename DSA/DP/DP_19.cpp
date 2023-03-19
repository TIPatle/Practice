#include <iostream>
#include <vector>

using namespace std;

vector<int> arr(1e5);

int minJumps(int i, int j, int step){

    if ( i >= j )
        return 1;

    if ( step == 1)
        return minJumps(i+1, j, arr[i+1]); 

    return minJumps(i+arr[i], j, arr[i]) + 1;

}

int main(){

    int n;
    cin>>n;

    
    for ( int i = 0; i<n; i++)
        cin>>arr[i];

    cout<<minJumps(0, n-1, arr[0]);
    

    return 0;

}