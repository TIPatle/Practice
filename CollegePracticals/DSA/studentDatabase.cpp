#include <iostream>
#include <fstream>

using namespace std;

class Student{

    string name;
    string rollNo;
    string div;
    string city;
    long long mobileNo;

    public:

        friend Student* search( string );

        void insert(){

            cout<<"Enter Student Name :- ";
            cin>>name;

            cout<<"Enter Student Roll no :- ";
            cin>>rollNo;

            cout<<"Enter Student Division :- ";
            cin>>div;

            cout<<"Enter Student City :- ";
            cin>>city;

            cout<<"Enter Student mobile no :- ";
            cin>>mobileNo;

        }

        void saveIs(){

            fstream f;
            f.open("./student.txt", ios::app );

            f<<name<<"\n";
            f<<rollNo<<"\n";
            f<<div<<"\n";
            f<<city<<"\n";
            f<<mobileNo<<"\n";
            f<<"\n";

            f.close();

        }

        void display(){

            cout<<"Student Name :- ";
            cout<<name<<endl;

            cout<<"Student Roll no :- ";
            cout<<rollNo<<endl;

            cout<<"Student Division :- ";
            cout<<div<<endl;

            cout<<"Student City :- ";
            cout<<city<<endl;

            cout<<"Student mobile no :- ";
            cout<<mobileNo<<endl;

        }


};

Student* search( string name ){

    fstream f;
    f.open("./student.txt", ios::in);

    string n = "";

    int i = 0;
    while ( n != name && !f.eof()){

        f>>n;
        f.seekg(i++);

    }

    Student* searchs = new Student();

    if ( n == name ){   

        
        f>>searchs->name;
        f>>searchs->rollNo;
        f>>searchs->div;
        f>>searchs->city;
        f>>searchs->mobileNo;

        return searchs;

    }

    f.close();

    return NULL;       

}

void save( Student* s, int n ){

    for ( int i = 0; i<n ; i++ )
        s[i].saveIs();

}

int main(){

    Student s[1000];

    int n;
    int i = 0;
    while (1){
        cout<<"1. Insert New Record"<<endl;
        cout<<"2. Save all New Record"<<endl;
        cout<<"3. Search Record"<<endl;
        cout<<"4. Exit "<<endl;
        cout<<"Enter Your choice :- ";
        cin>>n;

        string name;
        switch (n){

            case 1:
                s[i].insert();
                break;

            case 2:
                save(s, i);
                cout<<"Record saved Successfully."<<endl;
                break;

            case 3:

                cout<<"Enter the Student Name you want to search :- ";
                cin>>name;

                if ( search(name) != NULL ){

                    cout<<endl;
                    cout<<"Record found Successfully ."<<endl;
                    search(name)->display();
                    cout<<endl;

                }

                else
                    cout<<"Record if not present in Database."<<endl;


                break;

            case 4:
                cout<<"Program Terminated Sucessfully"<<endl;
                exit(0);
        

        }
        i++;

        cout<<endl;

    }


    return 0;

}