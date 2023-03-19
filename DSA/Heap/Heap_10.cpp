/* Heap Stl which is also known as priority queue which is basically a max heap */

#include <iostream>
#include <queue>

using namespace std;

int main(){

    priority_queue <int> pq;
    pq.push(8);  // logn time
    pq.push(3);
    pq.push(5);
    pq.push(9);

    while ( !pq.empty()){
        
        cout<<pq.top()<<" ";
        pq.pop();  // It will take logn time as deletes the element at the top heapify the given graph into heap

    }
    

    return 0;

}