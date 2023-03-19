#include <iostream>
#include <vector>
using namespace std;

class DisjointSet{
    private:
        vector<int> rank, size, parent;
    public:
        DisjointSet(int vertex){
            rank.resize(vertex, 0);
            size.resize(vertex, 1);
            parent.resize(vertex);
            for(int i=0; i<vertex; i++){
                parent[i]=i;
            }
        }

        int findParent(int vertex){
            if(parent[vertex]==vertex) return vertex;
            return parent[vertex]=findParent(parent[vertex]);
        }

        void unionSize(int vertex1, int vertex2){
            int parent1=findParent(vertex1);
            int parent2=findParent(vertex2);
            if(parent1==parent2) return;
            if(size[parent1]<size[parent2]){
                parent[parent1]=parent2;
                size[parent2]+=size[parent1];
            }else{
                parent[parent2]=parent1;
                size[parent1]+=size[parent2];
            }
        }

        void unionRank(int vertex1, int vertex2){
            int parent1=findParent(vertex1);
            int parent2=findParent(vertex2);
            if(parent1==parent2) return;
            if(rank[parent1]<rank[parent2]){
                parent[parent1]=parent2;
                rank[parent2]++;
            }else{
                parent[parent2]=parent1;
                rank[parent1]++;
            }
        }

};

int main(){
    DisjointSet ds(7);
    ds.unionSize(2, 3);
    ds.unionSize(4, 5);
    cout<<ds.findParent(2)<<endl;
    cout<<ds.findParent(4)<<endl;
    ds.unionSize(3, 4);
    cout<<ds.findParent(4)<<endl;
    return 0;
}