// #include <iostream>
// #include <limits>

// using namespace std;

// int main(){

//     int n;

//     if ( cin>>n ){

//         cout<<n<<endl;

//     }

//     else{

//         cout<<"Enter non numeric content"<<endl;

//     }

//     cin.ignore( 10000, '\n' );
//     cin.clear();

//     cin>>n;
//     cout<<n<<endl;
    
// }

// get_input2.cpp: Maggie Johnson
// Description: Illustrate the use of cin to get input
// and how to recover from errors.

#include <iostream>
using namespace std;

int main()
{
  int input_var = 0;
  // Enter the do while loop and stay there until either
  // a non-numeric is entered, or -1 is entered.  Note that
  // cin will accept any integer, 4, 40, 400, etc.
  do {
    cout << "Enter a number (-1 = quit): ";
    // The following line accepts input from the keyboard into
    // variable input_var.
    // cin returns false if an input operation fails, that is, if
    // something other than an int (the type of input_var) is entered.
    if (!(cin >> input_var)) {
      cout << "Please enter numbers only." << endl;
      cin.clear();
      cin.ignore(10000,'\n');
    } else if (input_var != -1) {
      cout << "You entered " << input_var << endl;
    }

  }
  while (input_var != -1);
  cout << "All done." << endl;

  return 0;
}