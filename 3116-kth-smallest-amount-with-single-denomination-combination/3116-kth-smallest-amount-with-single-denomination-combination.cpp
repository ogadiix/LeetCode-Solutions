class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        auto gcd = [](long long a, long long b) {
            while (b) {
                long long t = a % b;
                a = b;
                b = t;
            }
            return a;
        };

        auto count = [&](long long x) {
            long long res = 0;

            for (int mask = 1; mask < (1 << n); mask++) {
                long long l = 1;
                int bits = 0;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;
                        l = l / gcd(l, coins[i]) * coins[i];
                        if (l > x) break;
                    }
                }

                if (l <= x)
                    res += (bits & 1) ? x / l : -x / l;
            }

            return res;
        };

        long long l = 1, r = 1LL * *min_element(coins.begin(), coins.end()) * k;

        while (l < r) {
            long long mid = l + (r - l) / 2;

            if (count(mid) >= k)
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};