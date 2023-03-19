// Print all subset using bit manipulation
// {a, b, c} ---> {0, 0, 1} = c 
// Power set

#include <iostream>
#include <vector>

using namespace std;

int main(){

    int arr[] = {1, 2, 3};
    int n = 1<<3;

    vector<vector<int>> ans;
    for ( int i = 0; i<n; i++ ){

        vector <int> a;
        int num = i, count = 0;
        while ( num ){

            if ( num & 1 )
                a.push_back(arr[count]);
            

            count++;
            num = num >> 1;

        }
        
        ans.push_back(a);

    }

    for ( auto it : ans ){

        cout<<"{ ";
        for ( auto i : it )
            cout<<i<<" ";
        
        cout<<"}"<<endl;

    }

    return 0;

}