
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

vt<pair<int,int>>dir8 = {{0,1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1,1}};

bool check(int i, int j, int n, int m, vt<string>& v){
    int cnt = 0;
    for(auto it: dir8){
        int dx = i+ it.first;
        int dy = j + it.second;
        if(dx < 0 || dy < 0 || dx >= n || dy>=m)
            continue;
        if(v[dx][dy] == '@')
            cnt ++;
    }
    return (cnt < 4);

}

void solve()
{
    vector<pair<long long,long long>> ranges;
    string line;
    while(getline(cin, line)) {
        if(line.empty()) break;
        auto dash = line.find('-');
        long long lo = stoll(line.substr(0, dash));
        long long hi = stoll(line.substr(dash + 1));
        ranges.push_back({lo, hi});
    }
    sort(ranges.begin(), ranges.end());
    vector<pair<long long,long long>> merged;
    for(auto [lo, hi] : ranges) {
        if(!merged.empty() && lo <= merged.back().second + 1)
            merged.back().second = max(merged.back().second, hi);
        else
            merged.push_back({lo, hi});
    }

    //part 1
    int fresh = 0;
    long long id;
    while(cin >> id) {
        int lo = 0, hi = (int)merged.size() - 1, idx = -1;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(merged[mid].first <= id) { 
                idx = mid; 
                lo = mid + 1; 
            }
            else 
                hi = mid - 1;
        }
        if(idx != -1 && id <= merged[idx].second)
            fresh++;
    }
    
    //part2
    // ll fresh = 0;
    // for(auto it: merged){
    //     fresh += it.second - it.first +1;
    // }

    cout << fresh << "\n";
   
    
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
        nl;
        
    }
    end = clock();
     double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    // debug(time_taken);
    
 }
