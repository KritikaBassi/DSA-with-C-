#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
template <typename T>

class graph{
    public:
    unordered_map<T, list<T> > adj;

    void addEdge(T u, T v,bool direction){
        //0 -> undirected
        //1 -> directed
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};

vector<vector<int> > printAdjacency(int n,int m,vector<vector<int> > &edges){
    vector<int> ans[n];
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }
    vector<vector<int> > adje(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<ans[i].size();j++){
            adje[i].push_back(ans[i][j]);
        }
    }
    return adje;
}

int main(){
    int n;
    cout<<"Enter the number of nodes: "<<endl;
    cin>>n;

    int m;
    cout<<"Enter the number of edges: "<<endl;
    cin>>m;

    graph<int> g;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }
    g.printAdjList();

   
    return 0;
}