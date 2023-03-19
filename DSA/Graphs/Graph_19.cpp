#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main(){

    int n, m;
    cin>>n;

    map<int, int> ladder;

    for ( int i = 0; i<n; i++ ){

        int x, y;
        cin>>x>>y;

        ladder[x] = y;

    }

    cin>>m;

    map<int, int> snake;

    for ( int i = 0; i<m; i++){

        int x, y;
        cin>>x>>y;

        snake[x] = y;

    }

    queue <int> q;
    q.push(1);
    vector <bool> visited(101, 0);

    int found = 0;
    int count = 0;

    while ( !q.empty() && !found ){

        int size = q.size();

        while (size--){

            int current = q.front();
            q.pop();

            for ( int i = 1; i<7; i++){

                if ( current + i == 100 )
                    found = true;
                
                if ( current + i <= 100 && ladder[current+i] && !snake[current+i] && !visited[current+i] ){

                    visited[ladder[current+i]] = 1;

                    if ( ladder[current+i] == 100 )
                        found = true;

                    q.push(ladder[current+i]);

                }

                else if (current + i <= 100 && snake[current+i] && !visited[current+i]){
                    visited[snake[current+i]] = 1;

                    if ( snake[current+i] == 100 )
                        found = true;

                    q.push(snake[current+i]);

                }

                else if ( current + i <= 100 && !ladder[current+i] && !snake[current+i] && !visited[current+i]){

                    visited[current + i] = 1;
                    q.push(current+i);

                }


            }

        }

        count++;

    }
    

    if ( found )
        cout<<count<<endl;

    else
        cout<<-1;

    return 0;

}