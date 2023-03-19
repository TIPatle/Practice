#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comparator ( pair<int, int> T1, pair<int, int> T2 ){

    double v1 = double(T1.first) / double(T1.second);
    double v2 = double(T2.first) / double(T2.second);

    return v1 > v2;

}

int greatestValue(vector <pair<int, int> > v, int weight ){

    int value = 0;
    int w = 0;

    for ( int i = 0; i<v.size(); i++ ){

        if ( weight <= w + v[i].second ){

            value += double( double( weight - w ) * double(v[i].first / v[i].second));
            w = weight ;

            break;

        }
        
        value += v[i].first;
        w += v[i].second;

    }

    return value;

}

int main(){

    int n;
    cin>>n;

    vector <pair<int, int>> v(n);

    for ( int i = 0; i<n; i++ )
        cin>>v[i].first>>v[i].second;

    sort(v.begin(), v.end(), comparator);

    int maxWeight;
    cout<<"Enter a weight Which Theif can Carry :- ";
    cin>>maxWeight;

    for ( auto it : v )
        cout<<it.first<<" "<<it.second<<endl;

    cout<<greatestValue(v, maxWeight);

    return 0;

}