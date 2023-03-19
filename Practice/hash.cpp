#include <iostream>
#include <vector>

using namespace std;

vector <long long int> hash_table[10];

int hashfunction( long long int i ){

    return i % 10;

}

bool search_phoneno ( long long int phoneno ){

    for ( auto it : hash_table[hashfunction(phoneno)]){

        if ( it == phoneno )
            return 1;

    }

    return 0;

}


int main(){

    cout<<"Enter the number of Reccords you want to add to a database :- ";

    int n;
    cin>>n;

    long long int phoneno;
    while (n--){

        cout<<"Enter Phone number :- ";
        cin>>phoneno;

        hash_table[hashfunction(phoneno)].push_back(phoneno);

    }

    cout <<"Enter the Phone no you want to search :- ";
    cin>>phoneno;

    bool found =  search_phoneno(phoneno);

    if ( !found ){

        cout<<"Phone No is not existed in Phone Database "<<endl;

    }

    else {

        cout<<"Phone no :- "<<phoneno<<" is Present in your database "<<endl;

    }



    return 0;

}