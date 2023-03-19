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

int binSearch( int* arr1, int* arr2, int n, int m, int k ){

    if ( k ==1 )
        return min( arr1[0], arr2[0]);

    int totalLen = n + m;
    int s1 = 0, s2 = 0;
    int e1 = n-1, e2 = m-1;

    while( s1 <= e1 && s2 <= e2 ){

        int mid1 = (s1 + e1)/2;
        int mid2 = (s2 + e2)/2;

        if ( (mid1+mid2+2) == k ){

            return max( arr1[mid1], arr2[mid2]);

        }

        else if ( (mid1+mid2+2) > k ){

            if ( arr1[mid1] < arr2[mid2] )
                e2 = mid2-1;

            else    
                e1 = mid1-1;


        }

        else {

            if ( arr1[mid1] < arr2[mid2] )
                s1 = mid1+1;

            else    
                s2 = mid1+1;

        }

    }
    
    return -1;

}

int median( int* arr1, int* arr2, int n, int m ){

    if ( n == m && n == 0 )
        return -1;

    if ( n == 0 ){

        if ( m % 2 == 1 )
            return arr2[m/2];

        else  
            return (arr2[m/2] + arr2[m/2+1]);

    }

    if ( m == 0 ){

        if ( n % 2 == 1 )
            return arr1[n/2];

        else  
            return (arr1[n/2] + arr1[n/2+1]);

    }

    if ( (n+m) % 2 == 0)
        return (binSearch(arr1, arr2, n, m, (n+m)/2) + binSearch(arr1, arr2, n, m, (n+m)/2+1));
    
    return binSearch(arr1, arr2, n, m, (n+m)/2);

}

int main(){
 
    int t;
    cin>>t;

    while(t--){

        int n, m;
        cin>>n;

        int arr1[n];
        for ( int i = 0; i<n; i++ )
            cin>>arr1[i];

        cin>>m;

        int arr2[m];
        for ( int i = 0; i<m; i++ )
            cin>>arr2[i];

        cout<<median(arr1, arr2, n, m)<<endl;

    }


    return 0;

}