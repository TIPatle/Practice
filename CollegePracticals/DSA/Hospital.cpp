#include <iostream>
#include <queue>

using namespace std;

int main(){

    cout<<"Enter the number of paitent :- ";
    int n;
    cin>>n;

    cout<<"1. General Paitent \n2. Non-Serious\n3. Serious\n";

    int val;
    priority_queue <int> pq;

    for ( int i = 0; i<n; i++ ){

        cout<<"Enter Paitent category :- ";
        cin>>val;

        if ( val > 3 || val < 1){

            cout<<"Error Occurred Try again!!!"<<endl;
            i--;
            continue;

        }

        pq.push(val);

    }

    int serious = 0;
    int nonSerious = 0;
    int general = 0;

    cout<<"Servies Should be given in this order :- ";
    while ( !pq.empty() ){

        switch (pq.top()){

            case 1:
                general++;
                break;
            
            case 2:
                nonSerious++;
                break;
            case 3:
                serious++;
                break;

        }

        cout<<pq.top()<<"-->";

        pq.pop();

    }

    cout<<"NULL"<<endl;

    cout<<"Serious :- "<<serious<<endl;
    cout<<"Non Serious :- "<<nonSerious<<endl;
    cout<<"General :- "<<general<<endl;

    return 0;

}