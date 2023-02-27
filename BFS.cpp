#include<bits/stdc++.h>
using namespace std;

struct vertex
{
    string color;
    int d,r;
};

struct vertex vrtx[100];


void bfs(vector<vector<int>> &graph,int source){
    for(int i=0;i<graph.size();i++){
        vrtx[i].color = "White";
        vrtx[i].d = INT32_MAX;
        vrtx[i].r = 0;
    }

    vrtx[source].color = "Gray";
    vrtx[source].d = 0;
    vrtx[source].r = 0;

    queue<int>q;
    q.push(source);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v:graph[u]){
            if(vrtx[v].color=="White"){
                vrtx[v].color = "Gray";
                vrtx[v].d = vrtx[u].d + 1;
                vrtx[v].r = u;
                q.push(v);
            }
        }
        
        vrtx[u].color = "Black";
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
    bfs(graph,0);

    for(int i=0;i<n;i++){
        cout << "vertex " << i << " from " << vrtx[i].r << " Level : " << vrtx[i].d << endl;
    }
    return 0;
}