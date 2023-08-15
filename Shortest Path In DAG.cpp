void dfs(int u,vector<vector<pair<int,int>>>&adj,vector<int>& visited, vector<int>& ans){
  visited[u] = 1 ;
  for(auto it:adj[u]){
      if(!visited[it.first])
        dfs(it.first, adj,visited, ans);
  }
  ans.push_back(u);
}
vector<int> topoSort(int n,vector<vector<pair<int,int>>>&adj){
   vector<int>ans, visited(n,0);
   for(int i = 0 ; i < n; i++){
       if(!visited[i])
        dfs(i,adj, visited, ans);
   }
   reverse(ans.begin(),ans.end());
   return ans ;
}

vector<int> shortestPathinDAG(int n, int src, vector<vector<pair<int,int>>>&adj){
    vector<int> topo = topoSort(n,adj);
    vector<int>dist(n,1e9);
    dist[src] = 0;
    for(int i =0 ; i < n ;i++){
        int u= topo[i];
        for(auto it: adj[u]){
            int v = it.first ;
            int wt = it.second ;
            if(dist[v] > dist[u] + wt)
                dist[v] = dist[u] + wt;
        }
    }
    for(int i = 0 ; i < n;i++){
        if(dist[i] == 1e9)
            dist[i] = -1;
    }
    return dist;
}

// TC = O(E + V)

