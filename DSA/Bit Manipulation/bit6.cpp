// Basic bits functions

#include <iostream>

using namespace std;

bool isBitset ( int n, int i ){

    return n & (1 << i );

}

int setBit( int n, int i){

    return n | ( 1 << i );

}

int unsetBit( int n, int i ){

    return n & ( ~(1<<i) );

}

int removefirstSetBit( int n){

    int num = n;
    int count = 0;

    while ( num ){

        count++;
        num = num >> 1;

    }

    return n & (~(1 << (count - 1)));

}

int removeLastSetBit ( int n ){

    int num = n;
    int i = 0;

    while ( num == n ){

        num = num & (~(1<<i));
        i++;

    }
        
    return num;

}

int lastBitremove ( int n ){

    return n & n-1;

}

bool ispower2 ( int n ){

    if ( n & n -1 )
        return false;

    return true;

}

int countSetbit( int n ){

    int count = 0;

    for ( int i = 0; i<31; i++ ){

        if ( n & (1<<i))
            count++;

    }

    return count;

}

int setBitCount( int n ){

    int count = 0;
    while ( n ){
 
        n = n & ( n - 1);
        count ++;

    }

    return count;

}

int main(){

    cout<<setBitCount(14)<<endl;

    return 0;

}