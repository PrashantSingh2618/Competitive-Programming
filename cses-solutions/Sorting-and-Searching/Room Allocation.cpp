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
#define nl cout<<"\n";
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
#define YES cout<<"YES";
#define NO cout<<"NO";
#define yes cout<<"yes";
#define no cout<<"no";
 
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
 
struct data{
   int start , end , pos ;
};
 
bool comp(struct data A, struct data B){
   if(A.start == B.start){
      if(A.end == B.end)
         return A.pos < B.pos ;
      else
         return A.end < B.end ;
   }
   return A.start < B.start ;
}
 
struct pqData {
   int endTime, room;
};
class comp1{
public:
   bool operator()(struct pqData A, struct pqData B){
      return A.endTime > B.endTime;  // ascending order
   }
};
 
void solve()
{
   int n ;
   read(n) ;
   vt<struct data>v(n);
 
   vt<int>ans(n);
 
   rep(i,0,n){
      read(v[i].start, v[i].end) ;
      v[i].pos = i;
   }
 
   sort(all(v), comp) ;
 
   priority_queue<struct pqData, vector<struct pqData>, comp1>pq ;
 
   int j = 0, rooms  = 0;
   rep(i,0,n){
      if(sz(pq) == 0){
         j++ ;
 
         struct pqData x ;
         x.endTime = v[i].end ;
         x.room = j ;
 
         pq.push(x);
         ans[v[i].pos] = j;
      }
      else {
         auto top = pq.top();
         if(top.endTime < v[i].start){
            pq.pop() ;
 
            struct pqData x ;
            x.endTime = v[i].end ;
            x.room = top.room ;
 
            pq.push(x);
 
            ans[v[i].pos] = top.room;
         }
         else {
            j ++ ;
 
            struct pqData x ;
            x.endTime = v[i].end ;
            x.room = j ;
 
            pq.push(x);
            ans[v[i].pos] = j;
 
         }
      }
      rooms = max( rooms , sz(pq));
   }
   cout << rooms ;nl;
   for(auto it: ans)
      cout << it<<" ";
    
}
 
 int main()
 {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout); 
    #endif
 
    clock_t start, end; 
    start = clock(); 
    fio;
    ll k = 1;
    ll tc = 1;
    // cin>>tc;
    while(tc--){
       // cout<<"Case #"<<k<<": ";k++;
        solve();
        nl;
        
    }
    end = clock();
     double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    // debug(time_taken);
    
 }