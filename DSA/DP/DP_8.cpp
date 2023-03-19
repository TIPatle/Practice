#include <iostream>
#include <vector>

using namespace std;

vector <int> weight(1000, 0);
vector <int> values(1000, 0);


int maxValueKnapsack(int n, int w){

    if ( w <= 0 )
        return 0;

    if ( n <= 0)
        return 0;

    if ( weight[n-1] > w )
        return maxValueKnapsack(n-1, w);

    return max(maxValueKnapsack(n-1, w), maxValueKnapsack(n-1, w-weight[n-1]) + values[n-1]);

}

int main(){

    int n;
    cin>>n;

    for ( int i = 0; i<n; i++)
        cin>>weight[i];

    for ( int i = 0; i<n; i++)
        cin>>values[i];

    int w;
    cin>>w;

    cout<<maxValueKnapsack(n, w);

}