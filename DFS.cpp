#include<bits/stdc++.h>
using namespace std;

struct vertex
{
    string color;
    int d,r,f;
};

struct vertex vrtx[100];
int Time;

void DFS_VISIT(vector<vector<int>> &graph,int u){
    Time = Time+1;
    vrtx[u].d = Time;
    vrtx[u].color = "Gray";
    for(auto &v:graph[u]){
        if(vrtx[v].color=="White"){
            vrtx[v].r = u;
            DFS_VISIT(graph,v);
        }
    }
    vrtx[u].color = "Black";
    Time = Time+1;
    vrtx[u].f = Time;
}


void dfs(vector<vector<int>> &graph){
    for(int i=0;i<graph.size();i++){
        vrtx[i].color = "White";
        vrtx[i].r = 0;
    }
    Time = 0;
    for(int u=0;u<graph.size();u++){
        if(vrtx[u].color=="White"){
            DFS_VISIT(graph,u);
        }
    }
}





int main(){
    
    int n,edges;
    cout << "Enter the number of nodes : " ;
    cin >> n;
    cout << "Enter the number of edges : " ;
    cin >> edges;
    vector<vector<int>> graph(n,vector<int>());
    cout << "Enter all the edges : ";
    for(int i=0;i<n;i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(graph);

    for(int i=0;i<n;i++){
        cout << "vertex " << i << " from " << vrtx[i].r << " Visiting time:"  << vrtx[i].d << " Backing Time : " << vrtx[i].f << endl;
    }
    return 0;
}