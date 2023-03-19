#include <iostream>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        string x;
        cin>>x;

        string a = "";
        string b = "";

        char maxi = ' ';
        bool isone = 0;

        for ( int i = 0; i<n; i++ ){

            if ( maxi != ' ' ){

                a.push_back('0');
                b.push_back(x[i]);

                continue;

            }

            if ( x[i] == '2' && maxi == ' ' ){

                a.push_back('1');
                b.push_back('1');

            }

            else if ( x[i] == '1' ){

                a.push_back('1');
                b.push_back('0');

                if ( isone == 0 ){

                    isone = 1;
                    maxi = 'a';

                }

            }

            else {

                a.push_back('0');
                b.push_back('0');

            }

        }

        cout<<a<<endl;
        cout<<b<<endl;

    }

    return 0;

}