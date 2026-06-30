// To cal nCr 
class Fac {
public:

    int MOD;
    vector<int> fac, inv;
    Fac(int maxn, int _mod) {
        MOD = _mod;
        fac.resize(maxn, 1);
        auto mod_pow = [&] (int a, int n) {
            int r = 1;
            while (n) {
                if (n & 1) r = (1ll * r * a) % MOD;
                a = (1ll * a * a) % MOD;
                n /= 2;
            }
            return r;
        };
        for (int i = 1; i < maxn; ++i) fac[i] = (1ll * i * fac[i - 1]) % MOD;
        inv = fac;
        for (auto &x : inv) x = mod_pow(x, MOD - 2);
    }
    ll C(int n, int r) {
        if (n < r or r < 0) return 0;
        int res = (1ll * fac[n] * inv[r]) % MOD;
        return int((1ll * res * inv[n - r]) % MOD);
    };

};

void solve() {
    Fac fac(200005, 998244353);
    int n = 10, x = 2;

    ll ans = fac.C(n, x);
    cout << ans;

}
