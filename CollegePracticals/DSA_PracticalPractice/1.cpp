#include <iostream>
#include <vector>

using namespace std;

int main(){

    cout<<"Enter the number of phone number you want to our database :- ";
    long n;
    cin>>n;

    vector<vector<long long>> arr(10);
    long long phoneno;
    for ( int i = 0; i<n; i++ ){
        
        cout<<"Enter the Phone no :- ";
        cin>>phoneno;
        
        if ( phoneno >= 1e9  && phoneno < 1e10 ){

            long hash = phoneno % 10;
            arr[hash].push_back(phoneno);

        }

        else {

            cout<<"Invalid Phone no!!!"<<endl;
            cout<<"Try again!!!"<<endl;

            i--;

        }

    }

    cout<<"Enter the phone no you want to search :- "<<endl;
    cin>>phoneno;

    bool found = 0;
    for ( auto it : arr[phoneno%10])
        if ( it == phoneno )
            found = 1;

    if ( found )
        cout<<"Phone no is present in our phone book "<<endl;

    else 
        cout<<"Phone no is not present in our  phone book "<<endl;


    return 0;

}