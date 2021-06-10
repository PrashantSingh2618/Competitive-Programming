//cal ncr(n,r) to cal nCr
ll md=1e9+7;
ll fact[1000002],inv[1000002];
ll modex(ll a,ll p)
{
  if(p==0)
    return 1;
  else if(p%2==1)
  {
    return (a*modex(a,p-1))%md;
  }
  else
  {
    ll y=modex(a,p/2)%md;
    return (y*y)%md;
  }
}
void calculate()
{
  ll i,j,k;
  fact[0]=1;
  fact[1]=1;
  for(i=2;i<=1000000;i++)
  {
    fact[i]=(fact[i-1]*i)%md;
  }
  for(i=0;i<=1000000;i++)
  {
    inv[i]=modex(fact[i],md-2);
  }
}
ll ncr(ll n,ll r)
{
  return (((fact[n]*inv[r])%md)*inv[n-r])%md;
}
