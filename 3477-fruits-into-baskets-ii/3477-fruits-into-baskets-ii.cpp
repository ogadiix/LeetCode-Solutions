class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size(), ans = 0;
        vector<bool> used(n);

        for (int x : fruits) {
            bool ok = false;

            for (int i = 0; i < n; i++) {
                if (!used[i] && baskets[i] >= x) {
                    used[i] = true;
                    ok = true;
                    break;
                }
            }

            if (!ok) ans++;
        }

        return ans;
    }
};