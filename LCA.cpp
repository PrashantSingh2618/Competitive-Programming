
//  N is 100001
// in main first call -> parentanddepth ( adj , depth , n ) ;
// then int Lca= lca(depth, x , y);
// declare depth array in main of size n
int parent[N][32];

void dfslca(vector<int>* adj,bool visited[],int x,int depth[],int curd,int p){
    visited[x]=true;
    depth[x]=curd;
    parent[x][0]=p;    
    for(auto j=adj[x].begin();j!=adj[x].end();j++){
        if(!visited[*j]){
        dfslca(adj,visited,*j,depth,curd+1,x);
    }
        }

}

//parent sparse table
void parentanddepth(vector<int>* adj,int depth[],int n){
   memset(parent , -1 , sizeof(parent));
    bool visited[n];
    mem(visited,false);
    dfslca(adj,visited,0,depth,0,-1);
 
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
int lca(int depth[],int x,int y){
    if(depth[x]<depth[y])
        swap(x,y);
    int c=abs(depth[x]-depth[y]);
    if(c!=0){
    for(int i=0;i<=log2(c);i++){
     //   cout<<(c<<i);
        if((c>>i)&1){
        x=parent[x][i];
    //    cout<<x;
        }
    }
    }
//    cout<<x;
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
