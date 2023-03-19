#include <bits/stdc++.h>

#define N 1e7
#define M 1e5

#define vi vector<int>
#define vii vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pii pair<int, int>

#define rep(i, a, b) for(int i = a; i<b; i++)
#define decrep(i, a, b) for ( int i = a; i>=b; i--)

using namespace std;

void mergeSorted( int arr1[], int arr2[], int n, int m ){ // O(2*n+2*m)  O(n+m)

    int arr3[n+m];
    
    int i = 0, j = 0;
    int k = 0;

    while(i<n && j<m){

        if ( arr1[i] < arr2[j] ){

            arr3[k++] = arr1[i++];

        }

        else{

            arr3[k++] = arr2[j++];

        }

    }

    while( i<n ){

        arr3[k++] = arr1[i++];

    }

    while(j<m){

        arr3[k++] = arr2[j++];

    }

    k = 0;
    for ( i = 0; i<n; i++ ){

        arr1[i] = arr3[k++];

    }

    for ( j = 0; j<m; j++ ){

        arr2[j] = arr3[k++];

    }

}

void mergeSortedInsertion( int arr1[], int arr2[], int n, int m ){ // O(min(n, m)*O(m))  O(1)

    int i = 0, j = 0;
    int k = 0;

    while(i<n && j<m){

        if ( arr1[i] <= arr2[j] ){

            i++;

        }

        else{

            swap(arr1[i], arr2[j]);
            i++;

            k = j;
            while( k<m && arr2[k] > arr2[k+1] ){

                swap(arr2[k], arr2[k+1]);
                k++;

            }

        }

    }

}

void mergeSortedGap( int arr1[], int arr2[], int n, int m ){ // O(min(n, m))  O(1)

    int i = 0;
    int gap = (n+m)/2;

    while( i<(n+m) && gap > 0 && (i+gap) < (n+m) ){

        if ( i < n && (i+gap) < n ){

            if ( arr1[i] > arr1[i+gap] )
                swap(arr1[i], arr1[i+gap]);

        }

        else if ( i <n && (i+gap) >= n ){

            if ( arr1[i] > arr2[i+gap-n] ){

                swap( arr1[i], arr2[i+gap-n]);

            }

        }

        else if ( i > n ){

            if ( arr2[i-n] > arr2[i+gap-n] ){

                swap( arr2[i-n], arr2[i+gap-n]);

            }

        }

        i++;

        cout<<gap<<"  ";
        for ( int i = 0; i<n; i++ )
            cout<<arr1[i]<<" ";

        for ( int j = 0; j<m; j++ )
            cout<<arr2[j]<<" ";

        cout<<endl;

        if ( (i+gap) >= (n+m) ){

            i = 0;
            gap = gap/2;

        }

    }

}

int main(){
    
    int n, m;
    cin>>n>>m;

    int arr1[n];
    int arr2[m];

    for ( int i = 0; i<n; i++ )
        cin>>arr1[i];

    for ( int i = 0; i<m; i++ )
        cin>>arr2[i];

    mergeSortedGap(arr1, arr2, n, m );

    for ( int i = 0; i<n; i++ )
        cout<<arr1[i]<<" ";

    for ( int j = 0; j<m; j++ )
        cout<<arr2[j]<<" ";


    return 0;

}