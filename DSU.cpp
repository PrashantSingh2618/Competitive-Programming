
ll root (vector<ll>&parent ,ll i)
{
    while(parenty[i] != i)
    {
        parent[i] = parent[parent[i]] ; 
        i = parent[i]; 
    }
    return i;
}
void union(vector<ll>&parent,vector<ll>&size,ll A, ll B)
{
    ll root_A = root(parent,A);
    ll root_B = root(parent,B);
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
// Call DSU_init to initilise initial values
void DSU_init(vector<ll>&parent,vector<ll>&size,ll n)
{
    for(int i = 0 ; i < n;i++)
    {
        parent[i] = i ;
        size[i] = 1;
    }
}
