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
#define nl "\n";
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

using ull = unsigned long long;

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
inline ll add(ll x, ll y) { x += y; if (x >= mod) x -= mod; return x;}
inline ll sub(ll x, ll y) { x -= y; if (x < 0) x += mod; return x;}
inline ll mul(ll x, ll y) { return (x * 1ll * y) % mod;}
inline ll powr(ll a, ll b) {
    ll x = 1 % mod;
    while (b) {
        if (b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}
inline ll inv(ll a) { return powr(a, mod - 2);}
inline ll bitmask(int k) { return (1LL << (k + 1)) - 1; }

int get_inv(int x, int n, vt<int>& pos) {
    if (x < 1 || x >= n) return 0;
    return (pos[x] > pos[x + 1]);
}

struct data {
    int startTime, endTime;
    data(int st, int et) {
        startTime = st;
        endTime = et;
    }
};

bool comp(struct data A, struct data B) {
    if (A.endTime == B.endTime)
        return A.startTime < B.startTime;
    return A.endTime < B.endTime;
}
class comp1 {
public:
    bool operator()(struct data A, struct data B) {
        if (A.endTime == B.endTime)
            return A.startTime > B.startTime;
        return A.endTime > B.endTime;
    }
};

// Hint 💡: Find max subsequence of the given string

string findMaxMDigit(const std::string& num_str, int m) {
    int n = num_str.length();
    if (n < m) {
        return "0";
    }

    std::string result = "";
    int rem = n - m;

    for (char digit : num_str) {
        while (!result.empty() && result.back() < digit && rem > 0) {
            result.pop_back(); 
            rem--;             
        }
        result.push_back(digit);
    }

    if (sz(result) > m) {
        result = result.substr(0, m);
    }

    return result;
}

void solve() {
    string s;
    vector<string> num;

    ll sum = 0;
    int m = 12;

    while (cin >> s) {
        string res = findMaxMDigit(s, m);
        ll s = 0, k = 0;
        for (int i = sz(res) - 1; i >= 0; i--) {
            s += (res[i] - '0') * (pow(10, k));
            k++;
        }
        sum += s;

    }
    cout << sum;

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

    // cin >> tc;
    while (tc--) {
        // cout<<"Case #"<<k<<": ";k++;
        solve();
        // nl;

    }
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    debug(time_taken);

}
