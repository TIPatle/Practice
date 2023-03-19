#include <iostream>
#include <fstream>

using namespace std;

class File{

    string filename;

    public:

        void create (string name){

            fstream f;
            filename = "./"+name+".txt";
            f.open(filename, ios::app);

        }

        void open (string name ){
            
            fstream f;
            filename = "./"+name+".txt";
            f.open(filename, ios::in);

            if (!f){

                cout<<"File is not present in directory."<<endl;
                cout<<"Creating one for you"<<endl;

                create(name);

            }
            f.close();

        }

        void append (string s ){

            fstream f;
            f.open( filename, ios::app );

            f<<s;

            f.close();

        }

        void write (string s){

            fstream f;
            f.open(filename, ios::out);

            f<<s;

            f.close();

        }

        void readDisplay ( string s ){

            fstream f;
            f.open(filename);

            string ans;
            while (!f.eof()){

                f>>ans;
                cout<<ans<<" ";

            }

        }

        void deletefile( char* c ){

            remove(c);
            
        }


};

int main(){

    File f;

    label:

    while(1){
        
        cout<<endl;
        cout<<"1. Create"<<endl;
        cout<<"2. Open"<<endl;
        cout<<"3. append"<<endl;
        cout<<"4. Write"<<endl;
        cout<<"5. Read & Display"<<endl;
        cout<<"6. Delete a File"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<endl;

        cout<<"Enter Your choice :- ";
        int n;
        cin>>n;

        char s[100];

        switch (n){

        case 1:

            
            cout<<"Enter a name of file :- ";
            cin>>s;

            f.create(s);

            break;
        
        case 2:

            cout<<"Enter a name of file :- ";
            cin>>s;

            f.open(s);

            break;

        case 3:

            cout<<"Enter a data to append in file :- ";
            cin>>s;

            f.append(s);

            break;

        case 4:

            cout<<"Enter a data to write in file :- ";
            cin>>s;

            f.write(s);

            break;

        case 5:

            cout<<"Reading the file"<<endl;

            f.readDisplay(s);

            break;

        case 6:

            cout<<"Enter the name of file you want to delete :- ";
            cin>>s;

            f.deletefile(s);

            break;

        case 7:
            cout<<"Program Terminated Successfully "<<endl;
            exit(0);

        default :

            cout<<"Invalid Input"<<endl;
            cout<<"Try Again !!!"<<endl;
            goto label;
        
        }
        

    }

    return 0;

}