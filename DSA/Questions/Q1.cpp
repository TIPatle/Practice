// Min & Max In a Array

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

pair<int, int> min_max_element ( int* start, int* end ){

    int mini = INT_MAX;
    int maxi = INT_MIN;

    for ( auto it = start ; it != end ; it++ ){

        mini = min(mini, *it);
        maxi = max(maxi, *it);         

    }

    return {mini, maxi};

}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for ( int i = 0; i<n; i++ )
        cin>>arr[i];

    cout <<endl<<endl;

    pair<int, int> ans = min_max_element(arr, arr+n);
    cout<<ans.first<<" "<<ans.second<<endl;

    return 0;

}