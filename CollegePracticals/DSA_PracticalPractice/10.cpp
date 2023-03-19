#include <iostream>
#include<queue>

using namespace std;

int main(){

    priority_queue <int> pq;

    cout<<"Enter the number of paitent :- ";
    int n;
    cin>>n;


    cout<<"\t\tMenu "<<endl;
    cout<<"1. Genral Paitent "<<endl;
    cout<<"2. Non Serious "<<endl;
    cout<<"3. Serious "<<endl;

    int input;
    for ( int i = 0; i<n; i++ ){

        cin>>input;

        if ( input > 3 && input < 1 ){

            cout<<"Invalid Input !!!"<<endl;
            cout<<"Try again !!!"<<endl;

            i--;

        }

        else{

            cout<<"Element is added in priority queue "<<endl;
            pq.push(input);

        }

    }

    int serious = 0;
    int nonserious = 0;
    int general = 0;

    while( !pq.empty() ){

        auto it = pq.top();
        pq.pop();

        if ( it == 1 )
            general++;

        else if ( it == 2)
            nonserious++;

        else 
            serious++;

        cout<<it<<"---->";
    }

    cout<<"End"<<endl;

    cout<<"Serious :- "<<serious<<endl;
    cout<<"Non Serious :- "<<nonserious<<endl;
    cout<<"General :- "<<general<<endl;


    return  0;
    
}