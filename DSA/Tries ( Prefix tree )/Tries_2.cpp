#include <iostream>

using namespace std;

class triesnode{

    public:
        triesnode* next[2];

        triesnode(){

            next[0] = NULL;
            next[1] = NULL;

        }

};

triesnode* insert(int arr[], int n){

    triesnode* root = new triesnode();

    for ( int i = 0; i<n; i++ ){

        int num = arr[i];

        triesnode* curr = root;
        for (int j = 31 ; j>=0; j-- ){

            int bit = (num >> j) & 1;

            if ( curr->next[bit] == NULL )
                curr->next[bit] = new triesnode();

            curr = curr->next[bit];

        }

    }

    return root;

}

int helper(triesnode* root, int arr[], int n){

    int maxi = 0;
    for ( int i = 0; i<n; i++ ){

        int num = arr[i];
        int curr_max = 0; 
        triesnode* it = root;
        for ( int j = 31; j>= 0; j-- ){

            int bit = ((num>>i) & 1) ? 0 : 1;
            if ( it->next[bit] ){

                curr_max <<= 1;  // shift all bits to right
                curr_max |= 1;   // add a bit 

                it = it->next[bit];

            }

            else{

                curr_max <<= 1;  // shift all bits to right
                curr_max |= 0;   // add a bit 0 which is not needed
                
                it = it->next[bit xor 1];

            }

        }

        maxi = max(maxi, curr_max);

    }

    return maxi;

}

int main(){

    int arr[] = {3, 10, 5, 15, 2};
    int n = 5;
    triesnode* t = insert(arr, n);
    int maxiXOR = helper(t, arr, n);

    cout<<maxiXOR<<endl;

    return 0;

}