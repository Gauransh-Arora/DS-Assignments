//DFS
//Assuming the starting node is 0
#include<bits/stdc++.h>
using namespace std;

void dfsHelper(int node , vector<vector<int>> &adj, vector<int> &visited, vector<int> &dfs_traversal){
    visited[node] = 1;
    dfs_traversal.push_back(node);
    for(auto it: adj[node]){
        if(!visited[it]){
            dfsHelper(it, adj, visited, dfs_traversal);
        }
    }
}

vector<int> dfs(vector<vector<int>> &adj){
    vector<int> visited = vector<int>(adj.size(), 0);
    vector<int> dfs_traversal;
    int start = 0;
    dfsHelper(start, adj, visited, dfs_traversal);
    return dfs_traversal;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    cout << "Enter edges (u v):" << endl;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> result = dfs(adj);
    for(auto node: result){
        cout << node << " ";
    }
    return 0;
}