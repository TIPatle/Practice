// median of running stream

#include <iostream>
#include <queue>

using namespace std;

priority_queue <int, vector<int>, greater<int>> minHeap;
priority_queue <int, vector<int>> maxHeap;

int main(){

    int arr[] = {12, 14, 7, 20, 21, 67};

    for ( int i = 0; i<6; i++ ){

        if (minHeap.empty() && maxHeap.empty()){

            maxHeap.push(arr[i]);
            cout<<maxHeap.top()<<endl;

            continue;

        }

        if ( ( i ) % 2 != 0 ){

            minHeap.push(arr[i]);
            cout<<(minHeap.top() + maxHeap.top()) / 2 <<endl;

        }

        else{

            maxHeap.push(arr[i]);
            cout<<maxHeap.top()<<endl;

        }

    }

    return 0;

}