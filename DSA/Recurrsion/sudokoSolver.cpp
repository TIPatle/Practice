#include <bits/stdc++.h>

#define N 1e7
#define M 1e5

#define vi vector<int>
#define vii vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pii pair<int, int>

#define rep(i, a, b) for(int i = a; i<b; i++)
#define decrep(i, a, b) for ( int i = a; i>=b; i--)
#define repit(it, s) for ( auto it : s)

using namespace std;

int getPos(int n){
    if ( n < 3)
        return 0;
    if ( n < 6)
        return 3;
    return 6;
}

bool isSafe( vector<vector<char>>& board, int a, int b, int num ){
    for( int i = 0; i<9; i++){
        if(board[i][b] == '.' )
            continue;
        if(board[i][b] == num+'0')
            return false;
    }

    for ( int i = 0; i<9; i++ ){
        if(board[a][i] == '.')
            continue;
        if(board[a][i] == num+'0')
            return false;
    }   
    
    int p1 = getPos(a);
    int p2 = getPos(b);
    for ( int i = p1; i<p1+3; i++){
        for( int j = p2; j<p2+3; j++){
            if (board[i][j] == '.')
                continue;;
            if (board[i][j] == num+'0')
                return false;
        }
    }

    return true;
}

void print(vector<vector<char>>& board){
    for(auto it : board){
        for(auto i : it ){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool sudoSolve(vector<vector<char>>& board){
    for (int i = 0; i<9; i++ ){
        for(int j = 0; j<9; j++ ){
            if ( board[i][j] == '.' ){
                for(int k = 1; k<=9; k++){
                    if(isSafe(board, i, j, k)){
                        board[i][j] = k+'0';
                        if (sudoSolve(board))
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }

    return true;
}

void solve(){
    vector<vector<char>> board(9, vector<char>(9));
    for ( int i = 0; i<9; i++ ){
        for ( int j = 0; j<9; j++ ) 
            cin>>board[i][j];
    }
    cout<<sudoSolve(board)<<endl;
    print(board);
    
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--) 
        solve();

    return 0;

}