class Solution {
    static constexpr long long MOD = 1'000'000'007LL;

    struct Node {
        long long sum = 0;    // Sum of distinct counts
        long long sqSum = 0;  // Sum of squared distinct counts
        long long lazy = 0;   // Pending range addition
    };

    vector<Node> st;
    int n;

    void apply(int p, int l, int r, long long x) {
        long long len = r - l + 1;
        x %= MOD;

        // (a + x)^2 = a^2 + 2ax + x^2
        st[p].sqSum = (
            st[p].sqSum
            + 2LL * x % MOD * st[p].sum % MOD
            + x * x % MOD * len % MOD
        ) % MOD;

        st[p].sum = (st[p].sum + x * len) % MOD;
        st[p].lazy = (st[p].lazy + x) % MOD;
    }

    void push(int p, int l, int r) {
        if (st[p].lazy == 0 || l == r) return;

        int mid = (l + r) / 2;
        long long x = st[p].lazy;

        apply(p * 2, l, mid, x);
        apply(p * 2 + 1, mid + 1, r, x);

        st[p].lazy = 0;
    }

    void pull(int p) {
        st[p].sum = (st[p * 2].sum + st[p * 2 + 1].sum) % MOD;
        st[p].sqSum = (
            st[p * 2].sqSum + st[p * 2 + 1].sqSum
        ) % MOD;
    }

    void update(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            apply(p, l, r, 1);
            return;
        }

        push(p, l, r);

        int mid = (l + r) / 2;

        if (ql <= mid)
            update(p * 2, l, mid, ql, qr);

        if (qr > mid)
            update(p * 2 + 1, mid + 1, r, ql, qr);

        pull(p);
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        st.assign(4 * n, Node{});

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            int prev = last[nums[i]];

            // Every subarray [j, i] with j > prev
            // gains one distinct element.
            update(1, 0, n - 1, prev + 1, i);

            last[nums[i]] = i;

            // Sum of squares for all subarrays ending at i.
            ans = (ans + st[1].sqSum) % MOD;
        }

        return static_cast<int>(ans);
    }
};