#include<bits/stdc++.h>
using namespace std ;
 
 
#define vt vector
#define all(c) (c).begin(), (c).end()
#define rev(v) reverse(v)
#define sz(x) (int)(x).size()
#define ll long long
#define F first 
#define S second
#define pll pair<ll,ll>
#define ld long double
#define ar array
#define inf() ifstream cin("d.txt")
#define onf() ofstream cout("test.txt")
#define mod 1000000007
#define pb push_back
#define endl cout<<"\n";
#define prt1(a) cout<<a<<" "
#define prt2(a,b) cout<<a<<" "<<b<<" "
#define prt3(a,b,c) cout<<a<<" "<<b<<" "<<c<<" "
#define in(a) cin>>a
#define inn(a,b) cin>>a>>b
#define innn(a,b,c) cin>>a>>b>>c 
#define rep(i,st,end) for(ll i=st;i<end;i++)
#define repv(i,st,end) for(ll i=st;i>=end;i--)
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define TEST ll tc;cin>>tc;while(tc--)
#define EACH(x, a) for (auto& x: a)
 
template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {
    cin >> x;
}
void read(double& d) {
    string t;
    read(t);
    d=stod(t);
}
void read(long double& d) {
    string t;
    read(t);
    d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
    read(h);
    read(t...);
}
template<class A> void read(vt<A>& x) {
    EACH(a, x)
        read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
    EACH(a, x)
        read(a);
}
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
 
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a <<"\n";
    err(++it, args...);
}
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
    int x = 1 % mod;
    while(b){
        if(b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}
inline int inv(int a){ return powr(a, mod - 2);}
 
int f(vt<vt<int>>&dp,int i, int target, vt<int>&coins){
    if( i >= coins.size() || target < 0)
        return 0 ;
    if( target == 0)
        return 1 ;
    if(dp[i][target] != -1)
        return dp[i][target];
    int inc = f(dp,i,target-coins[i], coins);
    int notInc = f(dp,i+1,target, coins);
    return dp[i][target] = add(inc, notInc);
}
 
 
void solve()
{
    int n,x ;
    read(n,x);
    vt<int>v(n);
    read(v) ;
    vt<vt<int>>dp(n+1,vt<int>(x+1,0));
    dp[0][0] = 1 ;
    for(int i = 1 ; i<= n;i++){
        for(int j = 0  ;  j <= x ;j++){
            dp[i][j] = dp[i-1][j] ; // not included current 
            int reqd = j - v[i-1] ;
            if(reqd>=0)
                dp[i][j] = add(dp[i][j], dp[i][reqd]);
        }
    }
    cout<<dp[n][x];
      
}
 
 int main()
 {
    clock_t start, end; 
    start = clock(); 
    fio;
    ll k = 1;
    ll tc = 1;
    // cin>>tc;
    while(tc--){
       // cout<<"Case #"<<k<<": ";k++;
        solve();
        endl;
        
    }
    end = clock();
     double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    // debug(time_taken);
    
 }