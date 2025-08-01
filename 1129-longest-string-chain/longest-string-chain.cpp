class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        vector<int> dp(words.size(), 1);
        int maxi = 1;
        for (int i = 1; i < words.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (check(words[j], words[i]) && dp[j] + 1 > dp[i]) {
                    dp[i] = 1 + dp[j];
                }
            }
            if (maxi < dp[i])
                maxi = dp[i];
        }

        return maxi;
    }
    bool check(string& b, string& a) {
        if (a.size() != b.size() + 1)
            return false;

        int first = 0;
        int second = 0;

        while (first < a.size()) {
            if (a[first] == b[second]) {
                first++;
                second++;
            } else
                first++;
        }
        if (first == a.size() && second == b.size())
            return true;

        return false;
    }
};