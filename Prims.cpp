void solve(){
  ll n, m ;
  read(n,m) ;
  vt<vt<pair<ll,ll>>>adj(n) ;
  rep(i,0,m){
      ll a,b,c ;
      read(a,b,c) ;
      adj[a].pb({b,c}) ;
      adj[b].pb({a,c});
  }
  vt<ll>dist(n,1e9),mst(n,0),parent(n,-1);

  ll src = 0 ;
  dist[src] = 0 ; 
  priority_queue<pair<ll,ll>, vt<pair<ll,ll>>, greater<pair<ll,ll>>>pq ;
  pq.push({dist[src], src});
  rep(i,0,n-1){
      auto mn = pq.top() ;
      pq.pop();
      mst[mn.second] = 1 ;
      EACH(it,adj[mn.second]){
          if(!mst[it.first] and it.second < dist[it.first]){
              parent[it.first] = mn.second ;
              pq.push({dist[it.first], it.first});
              dist[it.first] = it.second ;
          }
      }
  }
  rep(i,1,n){
      cout<<parent[i]<<" - "<<i;
  endl;
  }
}
