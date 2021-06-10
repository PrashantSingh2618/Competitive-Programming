// call the diameter function and pass the adj list
void dfs(vt<vt<ll>>&adj , vt<ll>&visited ,ll u,vt<ll>&level)
{
    visited[u] = 1;
    EACH(it,adj[u])
    {
        if(!visited[it])
        {
            level[it]=level[u]+1;
            dfs(adj,visited,it,level);
        }
    }
}
ll diameter(vt<vt<ll>>&adj)
{
   vt<ll>level(n,0),visited(n,0);
  dfs(adj,visited,0,level);
 
  ll mx = *max_element(all(level));
  rep(i,0,n)
  {
    if(level[i]==mx)
    {
      mx = i;
      break;
    }
  }
  vt<ll>level1(n),visited1(n);
       
  dfs(adj,visited1,mx,level1);
  ll dia = *max_element(all(level1));
  return dia ;
}
 
