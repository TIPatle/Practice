// array element frequency hash table

/*
#include <iostream>

using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n] = {0};
    
    for ( int i = 0; i<n; i++ )
        cin>>arr[i];

    int hash[10] = {0};

    for ( int i = 0; i<n; i++ )
        hash[arr[i] % 10]++;


    for ( int i =0; i<10; i++)
        cout<<i<<" "<<hash[i]<<endl;

    return 0;

}

*/

#include <iostream>
#include <map>

using namespace std;

int main(){

    map<int, int > m;

    int n;
    cin>>n;

    for ( int i = 0; i<n; i++ ){

        int val;
        cin>>val;

        m[val]++;

    }

    for ( auto it : m )
        cout<<it.first<<" "<<it.second<<endl;

    return 0;

}