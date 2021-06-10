// call checkLoop(adj)
bool findLoop(ll v,vector<vector<ll>>&adj,vector<bool>&visited) 
{
  if(visited[v]==1)
    return 1;
  if(visited[v]==2)
    return 0;
  visited[v]=1;
  for(auto it:adj[v])
  {
    if(findLoop(it,visited))
      return 1;
  }
  visited[v]=2;
  return 0;
}

bool checkLoop(vector<vt<ll>>&adj)     
{
  ll start = 0,n = adj.size();
  vector<bool>visited(n,false); 
  for(ll i=start;i<n;i++) 
  {
    if(!visited[i] && findLoop(i,adj,,visited))
      return 1;
  }
  return 0;
}
