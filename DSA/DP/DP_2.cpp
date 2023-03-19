#include <iostream>
#include <vector>

using namespace std;

vector <long int> fibbonaci (1e7, -1);

int main(){

    int n;
    cin>>n;

    fibbonaci[0] = 0;
    fibbonaci[1] = 1;

    for ( int i = 2; i<=n; i++ )  
        // wrost time complexity is O(n) as it calculate the fibonnaci one after another by refrerring previous value
        fibbonaci[i] = fibbonaci[i-1] + fibbonaci[i-2];

    cout<<fibbonaci[n]<<endl;

    return 0;

}