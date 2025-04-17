// find shortest distance to all vertices from a source
vector<int> dijkstra(int n, int src, vector<vector<pair<int,int>>>&adj){
    vt<ll>dist(n, 1e9) ;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq ;
    pq.push({0,src}) ;
    dist[src] = 0 ;
    
    while(!pq.empty()) {
        auto top = pq.top() ;
        pq.pop() ;
        ll w = top.first ;
        ll u = top.second ;

        // to remove processing same node if it pushed again in queue and it's already relaxed
        if(dist[u] < w) continue;
        
        for(auto it: adj[u]){
            int v = it.first ;
            ll weight = it.second ;
            // cout<<u<<" ->"<<v<<" "<<weight;endl;
            if(dist[v] > w + weight){
                dist[v] = w + weight ;
                pq.push({dist[v], v}) ;
            }
        }
    }
    for(int i = 0 ; i < n;i++){
        if(dist[i] == 1e9)
            dist[i] = -1 ;
    }
    return dist;
}

// complexity -> O(ElogV)
// this is for Dirceted Cyclic graphs with no edge weights 
// However if there is no cycles then we can improve the TC to O(E+V) by using toposort method to find shortest path 
// check shortest-path-in-DAG.cpp
