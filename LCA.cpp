
class LCA {
public:
    int n = 1e5 + 1;
    vector<vector<int>>parent;
    vector<int>depth,visited;

    LCA(int _n){
        n = _n;
        parent.resize(n,vector<int>(32, -1));
        depth.resize(n, 0);
        visited.resize(n, 0);
    }

    void calLca(vector<vector<int>>& adj){
        parentanddepth(adj);
    }

    void dfslca(vector<vector<int>>& adj,int x,int curd,int p){
        visited[x]=true;
        depth[x]=curd;
        parent[x][0]=p;    
        for(auto it: adj[x]){
            if(!visited[it]){
                dfslca(adj,it,curd+1,x);
            }
        }
    }

    //parent sparse table
    void parentanddepth(vector<vector<int>>& adj){
        dfslca(adj,0,0,-1);
     
        for(int i=1;i<=log2(n);i++){
            for(int j=0;j<n;j++){
                if(parent[j][i-1]!=-1){
                    int z=parent[j][i-1];
                    parent[j][i]=parent[z][i-1];
                }
            }
        }
    }

    //Required: depth and parent sparse table
    int lca(int x,int y){
        if(depth[x]<depth[y])
            swap(x,y);
        int c=abs(depth[x]-depth[y]);
        if(c!=0){
        for(int i=0;i<=log2(c);i++){
                if((c>>i)&1){
                x=parent[x][i];
                }
            }
        }
        if (x==y)
        return x;
        
        for(int i=31;i>=0;i--){
            if(parent[x][i]!=parent[y][i]){
                x=parent[x][i];
                y=parent[y][i];
            }
        }
        return parent[x][0];
    }
    int getDepth(int x){
        return depth[x];
    }
};

