// Kruskal's algorithm
// Minimum spanning tree 

#include <iostream>
#include <vector>
#include <algorithm>
#define N 1e5+6

using namespace  std;

vector <int> parent(N);
vector <int> size(N);

void makeset ( int v ){

    parent[v] = v;
    size[v] = 1;

}

int find_set( int v ){

    if ( parent[v] == v )
        return v;

    return parent[v] = find_set(parent[v]);

}

void unionsets( int a, int b ){

    int x = find_set(a);
    int y = find_set(b);

    if ( x != y ){

        if ( size[x] < size[y])
            swap(x, y);

        parent[y] = x;
        size[x] += size[y];

    }

}

int main(){

    for ( int i = 0; i<N; i++ )
        makeset(i);

    int n, m;
    cin>>n>>m;

    vector <vector<int>> edges;
    for ( int i = 0; i<m; i++){

        int w, x , y;
        cin>>x>>y>>w;

        edges.push_back({w, x, y});

    }

    int mst = 0 ;
    sort ( edges.begin(), edges.end());
    
    for ( auto it : edges ){

        int w = it[0];
        int x = it[1];
        int y = it[2];

        int a = find_set(x);
        int b = find_set(y);

        if ( a == b)
            continue;

        else {
            
            cout<<x<<" "<<y<<endl;
            mst += w;
            unionsets(x, y);

        }
        

    }

    cout<<"Minimun spanning tree :- "<<mst<<endl;

    return 0;

}