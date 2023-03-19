// Genrally sorting is done first  
// some time we dont know we are using greedy technique because it comes from inside

// Indian Coin Change Problem

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> coins;

int MinNoChange(int Note){

    int change = 0;
    int sumCurrency = 0;

    int index = 0;

    while ( Note != sumCurrency  ){

        if ( sumCurrency + coins[index] > Note ){

            index++;
            continue;

        }

        sumCurrency += coins[index];
        cout<<coins[index]<<" ";
        change++;

    }

    return change;

}

int main(){

    int NumChange;
    cin>>NumChange;

    int c;
    for ( int i = 0; i<NumChange; i++ ){

        cin>>c;
        coins.push_back(c);

    }

    sort(coins.begin(), coins.end(), greater<int> ());

    int Value;
    cin>> Value;

    cout<<endl<<MinNoChange(Value);

    return 0;

}