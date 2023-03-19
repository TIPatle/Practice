#include <iostream>

using namespace std;

int main(){

    int t;
    cin>>t;

    while (t--){

        int n;
        cin>>n;

        int first = (n-1)*3;
        int second = ((n-1)/ 2) *3;

        cout<<first-second<<endl;

    }

    return 0;

}