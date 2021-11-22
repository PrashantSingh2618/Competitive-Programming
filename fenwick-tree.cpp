// 1 based index
// for sum call query(fen,r)-query(fen,l-1) 
void update(vt<ll>&fen, ll ind, ll val,ll n)
{
    while (ind <= n) 
    {
    	fen[ind]++;
    	ind += ind & (-ind);
    }
}
ll query(vt<ll>&fen,ll ind){
    ll s =  0;
    while(ind>0)
    {
        s+=fen[ind];
        ind -= ind&-ind;
    }
    return s ;
}
