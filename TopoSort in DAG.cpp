// using DFS
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

// TC - O(E+V)


// using BFS 

 vector<int> topoSort(int n, vector<vector<int>>& adj) {
    vector<int>ans, indegree(n,0);
    for(int i = 0 ; i < n ;i++){
        for(auto it: adj[i])
            indegree[it] ++ ;
    }
    queue<int>q;
    for(int i = 0 ; i < n;i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    while(!q.empty()){
        auto top = q.front();q.pop();
        ans.push_back(top);
        for(auto it: adj[top]){
            indegree[it] -- ;
            if(indegree[it] == 0)
                q.push(it);
        }
    }
   if(ans.size() == n)
       return ans;
    return {} ; // toposort cannot be formed
}

