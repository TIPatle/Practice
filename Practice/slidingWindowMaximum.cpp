#include <iostream>
#include <queue>
#include <climits>

using namespace std;

deque <int> dq;

void maxi ( int* start, int* end ){

    int maxx = INT_MIN;
    
    for ( auto it = start ; it != end; it++ )
        maxx = max(*it, maxx);

    cout<<maxx<<" ";

}

void insertatfirst(int* start, int* end, int key ){

    for ( auto it = start ; it != end -1; it ++ )
        *it = *(it+1);

    *end = key;

}

void printMaximumK( int n, int k ){

    int arr[k];
    for ( int i = 0; i<k; i++ ){

        arr[i] = dq.front();
        dq.pop_front();

    }

    while(!dq.empty()){

        insertatfirst(arr, arr+k, dq.front());
        maxi(arr, arr+k);
        dq.pop_front();

    }

}

int main(){

    int n, k;
    cin>>n, k;

    for ( int i = 0; i<n; i++ ){

        int val;
        cin>>val;

        dq.push_back(val);

    }

    printMaximumK(n, k);

    return 0;

}