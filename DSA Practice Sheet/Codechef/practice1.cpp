/*

Description :

JJ has an array AA initially of length NN. He can perform the following operation on AA:
1) Pick any index i (1<i<|A|) such that Ai > 1
2) Select any two integers X and Y such that X + Y = Ai and X, Y >= 1
3) Replace Ai with X and Y

Note that the length of the array increases by 1 after each operation.

JJ wants to make AA palindromic. Find the minimum number of operations to do so.
It is guaranteed that A can be converted to a palindromic array by using the above operation.
Note: An array is called a palindrome if it reads the same backwards and forwards, 
for e.g. [1, 3, 3, 1][1,3,3,1] and [6, 2, 6][6,2,6] are palindromic.

Input           Output
3                 2  
4                 0
3 7 6 4           4    
5
1 4 5 4 1
5
1 2 3 4 5

*/

#include <iostream>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int i = 0;
        int j = n - 1;

        int first = arr[i];
        int last = arr[j];

        int ans = 0;

        while (i < j)
        {

            if (first == last)
            {

                i++;
                j--;

                first = arr[i];
                last = arr[j];
            }

            else if (first > last)
            {

                j--;
                first = first - last;
                last = arr[j];

                ans++;
            }

            else if (first < last)
            {

                i++;
                last = last - first;
                first = arr[i];

                ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
