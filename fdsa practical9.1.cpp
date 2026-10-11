#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> g[100];
bool vis[100];

void DFS(int s){
    vis[s]=1;
    cout<<s<<" ";
    for(int v:g[s])
        if(!vis[v]) DFS(v);
}

void BFS(int s){
    for(int i=0;i<100;i++) vis[i]=0;
    queue<int> q;
    q.push(s);
    vis[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int v:g[u])
            if(!vis[v]){
                vis[v]=1;
                q.push(v);
            }
    }
}

int main(){
    int n,m,u,v,s;
    cout<<"Enter vertices and edges: ";
    cin>>n>>m;
    cout<<"Enter edges:\n";
    while(m--){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout<<"Enter start vertex: ";
    cin>>s;
    cout<<"DFS: ";
    DFS(s);
    cout<<"\nBFS: ";
    BFS(s);
}
