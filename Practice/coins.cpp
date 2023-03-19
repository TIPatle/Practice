#include <iostream>

using namespace std;

int main(){

    int note;
    cin>>note;

    int c100 = 0;
    int c50 = 0;
    int c20 = 0;
    int c1 = 0;

    int arr[] = {100, 50, 20, 1};
    int index = 0;

    while ( note && index < 4 ){

        int x = note / arr[index];

        switch (arr[index])
        {
            
            case (100) :
                if (x)
                    c100 = x;
                break;

            case (50):
                if (x)
                    c50 = x;
                break;

            case (20):
                if (x)
                    c20 = x;
                break;

            case (1):
                if (x)
                    c1 = x;
                break;

        }

        note %= arr[index];

        if ( !x )
            index++;

    }

    cout<<c100<<" * 100  + "<<c50<<" * 50 + "<<c20<<" * 20 + "<<c1<<" * 1"<<endl;

    return 0;

}