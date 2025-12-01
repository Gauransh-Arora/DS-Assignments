//BFS
//Assuming nodes are numbered from 0 to n-1
#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int node, vector<vector<int>> &adj){
    vector<int> visited(adj.size(), 0);
    vector<int> bfs_traversal;
    queue<int> q;
    visited[node] = 1;
    q.push(node);
    while (!q.empty()){
        int curr = q.front();
        q.pop();
        bfs_traversal.push_back(curr);
        for(auto it: adj[curr]){
            if(!visited[it]){
                visited[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs_traversal;    
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int start_node;
    cin >> start_node;
    vector<int> result = bfs(start_node, adj);
    for(auto node: result){
        cout << node << " ";
    }
    return 0;
}