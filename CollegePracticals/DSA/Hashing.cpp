#include <iostream>
#include <vector>
                        // ------ Coded By Tushar Patle
using namespace std;

vector <vector<pair<long long int, string >> > hash_table(10);

int hashfunction( long long int i ){

    return i % 10;

}

pair<long long int, string> search_phoneno ( long long int phoneno ){

    for ( auto it : hash_table[hashfunction(phoneno)]){

        if ( it.first == phoneno )
            return it;

    }

    return {-1, ""};

}

int main(){

    cout<<"Enter the number of Reccords you want to add to a database :- ";

    int n;
    cin>>n;

    string name;
    long long int phoneno;
    pair<long long int, string> p;
    while (n--){

        prev:

        cout<<"Enter name :- ";
        cin>>name;

        cout<<"Enter Phone number :- ";
        cin>>phoneno;

        if( phoneno > 1e10 || phoneno <= 1e9  ){

            cout<<"Invalid Phone Please enter the data again..."<<endl;
            goto prev;

        }



        p.first = phoneno;
        p.second = name;

        hash_table[hashfunction(p.first)].push_back(p);

    }

    label:

    cout <<"Enter the Phone no you want to search :- ";
    cin>>phoneno;

    auto Person =  search_phoneno(phoneno);

    if ( Person.first == -1 ){

        cout<<"Phone No is not existed in Phone Database "<<endl;
        goto label;

    }

    else {

        cout<<"Name     :- "<<Person.second<<endl;
        cout<<"Phone no :- "<<Person.first<<endl;

    }



    return 0;

}