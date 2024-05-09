class DSU {
    int N;
public:
    vector<int> parent, size;

    DSU(int n){
        N = n;
        parent.resize(N);
        size.resize(N);

        for(int i = 0 ; i < N;i++){
            parent[i] = i ;
            size[i] = 1;
        }
    }

    int root(int i)
    {
        while(parent[i] != i)
        {
            parent[i] = parent[parent[i]] ; 
            i = parent[i]; 
        }
        return i;
    }

    void _union(int A, int B)
    {
        int root_A = root(A);
        int root_B = root(B);
        if(size[root_A] < size[root_B])
        {
            parent[ root_A ] = parent[root_B];
            size[root_B] += size[root_A];
        }
        else
        {
            parent[ root_B ] = parent[root_A];
            size[root_A] += size[root_B];
        }

    }
};
