#include <iostream>
#include <vector>

using namespace std;

vector <int> v;

int upperBound( int l, int r, int key ){

    int mid;
    int indx = r;
    while( l <= r ){

        mid = (l + r) / 2;

        if ( v[mid] >= key ){

            if ( v[indx] <= key )
                indx = mid;

            else if( v[mid] < v[indx] )
                indx = mid;

            r = mid - 1;

        }
        
        else if ( v[mid] < key )
            l = mid + 1;

    }

    return indx;


}

void reverse ( int l, int r ){

    if ( r - l == 1){

        swap(v[l], v[r]);
        return ;
        
    }

    while( l <= r )
        swap(v[l++], v[r--]);

}

void nextPermutation(){

    int n = v.size();

    if ( n == 1 )
        return ;

    else if ( n == 2){

        swap(v[1], v[0]);
        return ;

    }


    for ( int i = n-2; i >= 0; i-- ){

        if ( v[i] < v[i+1] ){

            int indx = upperBound(i+1, n-1, v[i]);
            swap(v[i], v[indx]);
            reverse(i+1, n-1);

            return;

        }

    }

    reverse(0, n-1);

}

int main(){

    int n;
    cin>>n;

    v = vector <int> (n);
    for ( int i = 0; i<n; i++ )
        cin>>v[i];

    nextPermutation();

    for ( int i = 0; i<n; i++ )
        cout<<v[i]<<" ";

    cout<<endl;

    return 0;

}