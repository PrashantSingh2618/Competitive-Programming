// find shortest distance to all vertices from a source
vector<int> dijkstra(int n, int src, vector<vector<pair<int,int>>>&adj){
    vector<int>dist(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq ;
    pq.push({0,src});
    dist[src] = 0;
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        int u = top.second ;
        for(auto it: adj[u]){
            int v = it.first ;
            int wt = it.second ;
            if(dist[v] > dist[u]+wt){
                dist[v] = dist[u]+wt;
                pq.push({dist[v], v});
            }
        }
    }
    for(int i = 0 ; i < n;i++){
        if(dist[i] == INT_MAX)
            dist[i] = -1 ;
    }
    return dist;
}
