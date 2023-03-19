#include <iostream>

using namespace std;

long long hashh = 0;  // Stores 64 bit where 64th bit represent for negative and positive number 
                     // Takes 8 byte only ...
void add_element ( int n ){

    hashh = hashh | 1 << n;

}

void remove_element ( int n ){

    hashh = hashh & ~(1<<n);

}

void print(){

    int msk = hashh;

    int count = 0;
    while ( msk ){

        if ( msk & 1 )
            cout<<count<<" ";

        msk = msk >> 1;
        count++;

    }

}

int main(){

    add_element(5);
    add_element(1);
    add_element(5);
    add_element(3);
    remove_element(5);
    print();


    return 0;

}