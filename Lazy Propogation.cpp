class SegmentTree {
    vector<ll> tree, lazy;
    int N;

public:
    SegmentTree(int n) {
        N = n;

        tree.assign(4 * n + 1, 0); // Sum segment tree, initialize with 0
        lazy.assign(4 * n + 1, 0);
    }

    ll targetFunction(ll a, ll b) {
        return a + b;
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

    void lazyUpdate( ll low, ll high, ll l, ll r, ll val, ll index) {
        if (lazy[index] != 0) {
            tree[index] += (high - low + 1) * lazy[index];
            if (low != high ) {
                lazy[2 * index + 1] += lazy[index];
                lazy[2 * index + 2] += lazy[index];
            }
            lazy[index] = 0;
        }

        if (r < low || l > high) return;

        // Complete overlap
        if (l <= low && high <= r) {
            tree[index] += (high - low + 1) * val;
            if (low != high ) {
                lazy[2 * index + 1] += val;
                lazy[2 * index + 2] += val;
            }
            return;
        }
        ll mid = (low + high) >> 1 ;
        lazyUpdate(low, mid, l, r, val, 2 * index + 1);
        lazyUpdate(mid + 1, high, l, r, val, 2 * index + 2);

        tree[index] = targetFunction(tree[2 * index + 1], tree[2 * index + 2]);

    }

    ll lazyQuery(ll low, ll high, ll l, ll r, ll index) {
        if (lazy[index] != 0) {
            tree[index] += (high - low + 1) * lazy[index];
            if (low != high ) {
                lazy[2 * index + 1] += lazy[index];
                lazy[2 * index + 2] += lazy[index];
            }
            lazy[index] = 0;
        }
        if (r < low || l > high) return 0;

        // Complete overlap
        if (l <= low && high <= r) {
            return tree[index];
        }

        ll mid = (low + high) >> 1;
        ll left = lazyQuery(low, mid, l, r, 2 * index + 1);
        ll right = lazyQuery(mid + 1, high, l, r, 2 * index + 2);
        return targetFunction(left, right);

    }

    ll rangeQuery(int l, int r) {
        return query(0, N - 1, l - 1, r - 1, 0);
    }
};