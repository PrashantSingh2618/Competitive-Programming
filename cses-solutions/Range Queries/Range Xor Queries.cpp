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
    d = stod(t);
}
void read(long double& d) {
    string t;
    read(t);
    d = stold(t);
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
    cerr << *it << " = " << a << "\n";
    err(++it, args...);
}
inline int add(int x, int y) { x += y; if (x >= mod) x -= mod; return x;}
inline int sub(int x, int y) { x -= y; if (x < 0) x += mod; return x;}
inline int mul(int x, int y) { return (x * 1ll * y) % mod;}
inline int powr(int a, ll b) {
    int x = 1 % mod;
    while (b) {
        if (b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}
inline int inv(int a) { return powr(a, mod - 2);}
class Fenwick {
    vector<ll> tree;
    int N;
 
public:
    Fenwick(int n, vector<int>arr) {
        N = n;
        tree.assign(N + 1, 0);
    }
    // Point update: add val at index i (1-based)
    void update(int i, ll delta) {
        while (i <= N) {
            tree[i] += delta;
            i += (i & -i);
        }
    }
    // Query: sum from 1 to i (1-based)
    ll query(int i) {
        ll sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= (i & -i);
        }
        return sum;
    }
    // Range query: sum from l to r (inclusive, 1-based)
    ll rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
    void build(vector<int>& nums) {
        for (int i = 1; i <= N; ++i) {
            update(i, nums[i - 1]);
        }
    }
};
class SegmentTree {
    vector<ll> tree;
    int N;
 
public:
    SegmentTree(int n) {
        N = n;
        int x = (int)(ceil(log2(n)));
        int max_size = 2 * (int)pow(2, x) - 1;
        tree.assign(max_size, 0);  // Sum segment tree, initialize with 0
    }
 
    ll targetFunction(ll a, ll b) {
        return a ^ b;
    }
 
    void build(vector<ll>& nums, int low, int high, int index) {
        if (low == high) {
            tree[index] = nums[low];
            return;
        }
        int mid = (low + high) / 2;
        build(nums, low, mid, 2 * index + 1);
        build(nums, mid + 1, high, 2 * index + 2);
        tree[index] = targetFunction(tree[2 * index + 1], tree[2 * index + 2]);
    }
 
    ll query(int low, int high, int l, int r, int index) {
        // Out of range
        if (r < low || l > high) return 0;
 
        // Complete overlap
        if (l <= low && high <= r) return tree[index];
 
        int mid = (low + high) / 2;
        ll left = query(low, mid, l, r, 2 * index + 1);
        ll right = query(mid + 1, high, l, r, 2 * index + 2);
 
        return targetFunction(left, right);
    }
 
    void update(vector<ll>& nums, int low, int high, int index, int targetIndex, ll val) {
        if (low == high) {
            tree[index] = val;
            nums[targetIndex] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (targetIndex <= mid)
            update(nums, low, mid, 2 * index + 1, targetIndex, val);
        else
            update(nums, mid + 1, high, 2 * index + 2, targetIndex, val);
 
        tree[index] = targetFunction(tree[2 * index + 1] , tree[2 * index + 2]);
    }
 
    ll rangeQuery(int l, int r) {
        return query(0, N - 1, l - 1, r - 1, 0);
    }
};
 
void solve()
{
    ll n , q ;
    read(n, q);
    vector<ll>nums(n) ;
    read(nums);
    SegmentTree seg(n);
    seg.build(nums, 0, n - 1, 0);
 
    while (q--) {
        ll type = 2, l , r;
        read( l, r);
        if (type == 1) {
            seg.update(nums, 0, n - 1, 0, l - 1, r);
        }
        else {
            ll ans =  seg.rangeQuery(l, r );
            cout << ans << "\n";
        }
    }
 
}
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    clock_t start, end;
    start = clock();
    fio;
    ll tc = 1;
    // cin>>tc;
    while (tc--) {
        // cout<<"Case #"<<k<<": ";k++;
        solve();
        nl;
 
    }
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    debug(time_taken);
 
}