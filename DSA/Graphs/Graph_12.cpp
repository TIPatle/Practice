#include <iostream>
#include <vector>
#define N 1e5+6

using namespace std;

vector <int> parent(N);
vector <int> size(N);

void makeset(int v){

    parent[v] = v;
    size[v] = 1;

}

int find_set( int v ){

    if ( parent[v] == v )
        return v;

    return parent[v] = find_set(parent[v]);

}

void union_set( int x, int y ){

    int a = find_set(x);
    int b = find_set(y);

    if ( a != b ){

        if ( size[a] < size[b] )
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];

    }

}

int main(){

    for ( int i = 0; i<N; i++ )
        makeset(i);

    int n, m;
    cin>>n>>m;

    vector<vector<int>> edges;

    for ( int i = 0; i<m; i++ ){

        int x, y;
        cin>>x>>y;

        edges.push_back({x, y});

    }

    bool cycle = false;

    for ( auto it : edges ){

        int x = find_set(it[0]);
        int y = find_set(it[1]);

        if ( x == y ){

            cycle = true;

        }

        else
            union_set(it[0], it[1]);

    }

    if ( cycle )
        cout<<"Cycle is Present in Graph "<<endl;

    else 
        cout<<"Cycle is Not Present in Graph "<<endl;

    return 0;

}