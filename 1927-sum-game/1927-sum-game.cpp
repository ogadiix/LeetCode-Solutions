class Solution {
public:
    bool sumGame(string num) {
        int n = num.size(), a = 0, b = 0, x = 0, y = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') a++;
            else x += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') b++;
            else y += num[i] - '0';
        }

        return (a + b) % 2 || 2 * (x - y) != 9 * (b - a);
    }
};