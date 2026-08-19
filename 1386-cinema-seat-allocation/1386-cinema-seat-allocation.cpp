class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        for (auto &x : reservedSeats)
            mp[x[0]] |= 1 << (x[1] - 1);

        int ans = (n - mp.size()) * 2;

        for (auto &[row, mask] : mp) {
            if ((mask & 0b0111111110) == 0)
                ans += 2;
            else if ((mask & 0b0111100000) == 0 ||
                     (mask & 0b0001111000) == 0 ||
                     (mask & 0b0000011110) == 0)
                ans++;
        }

        return ans;
    }
};