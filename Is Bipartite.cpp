// check if a given undirected graph can be a bipartite or not
// DFS
bool dfs(int u,int currColor,vector<int>& visited, vector<int>& color, vector<vector<int>>&adj){
    visited[u] = 1 ;
    color[u] = currColor ;
    for(auto it: adj[u]){
        if(!visited[it] && !dfs(it,1 - currColor, visited, color,adj))
            return false ;
        else if(color[u] == color[it])
            return false;
    }
    return true;;
}
bool isBiPartite(int n, vector<vector<int>>& adj){
    vector<int>color(n,-1),visited(n, 0);
    for(int i = 0 ;i < n;i++){
        if(!visited[i] && !dfs(i,0,visited, color, adj))
            return false ;
    }
    return true;
}

