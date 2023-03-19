#include <iostream>
#include<fstream>

using namespace std;

class Student{

    string name, address, division ;
    int rollno;

    public:

        Student ( string n, string ad, string div, int roll ){

            name = n;
            address = ad;
            division = div;
            rollno = roll;

        }

        void insert (){

            cout<<"Enter the Student name :- "
            cin>>name;

            cout<<"En"


        }


};

int main(){


    return 0;

}